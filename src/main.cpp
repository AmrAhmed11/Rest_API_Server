#include <iostream>
#include <boost/beast/http.hpp>

namespace beast = boost::beast;
namespace http = beast::http;

http::response<http::string_body> request_handler(http::request<http::string_body> const& req){
    if(req.method() == http::verb::get){
        http::response<http::string_body> res{http::status::ok,req.version};
        res.set(http::field::server,"Rest_API_Server/1.0");
        res.set(http::field::content_type,"application/json");
        res.keep_alive(req.keep_alive());
        res.body() = R"({"message":"Hello, World!"})";
        res.prepare_payload()''
        return res;
    }else if(req.method() == http::verb::post && req.target() == "/user"){
        auto json_request = nlohmann::json::parse(req.body());
        std::string response_message = "Received: " + json_request.dump();
        nlohmann::json json_response = {{"message", response_message}};
        http::response<http::string_body> res{http::status::ok,req.version()};
        res.set(http::field::server,"Rest_API_Server/1.0");
        res.set(http::field::content_type,"application/json");
        res.keep_alive(req.keep_alive());
        res.body() = json_response.dump();
        res.prepare_payload()''
        return res;
    }else if(req.method() == http::verb::put && req.target() == "/user"){
        auto json_request = nlohmann::json::parse(req.body());
        std::string response_message = "Updated: " + json_request.dump();
        nlohmann::json json_response = {{"message", response_message}};
        http::response<http::string_body> res{http::status::ok,res.version()};
        res.set(http::field::server,"Rest_API_Server/1.0");
        res.set(http::field::content_type,"application/json");
        res.keep_alive(req.keep_alive());
        res.body() = json_response.dump();
        res.prepare_payload();
        return res;
    }else if(req.method() == http::verb::delete_){

    }
    return http::response<http::string_body>{http::status::bad_request, req.version()};
}




int main(){
    std::cout<<"Server is Running"<<std::endl;
    return 0;
}