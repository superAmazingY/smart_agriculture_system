#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class User : public drogon::HttpController<User> {
public:
    METHOD_LIST_BEGIN
        // use METHOD_ADD to add your custom processing function here;
        METHOD_ADD(User::loginInfo, "login?userId={1}&passwd={2}",Post,Options);  // url:  http://172.20.10.6:8099/user/login?userId={1}&passwd={2}   (登录API)
        METHOD_ADD(User::forgetPasswordInfo, "forgetPassword?userId={1}&passwd={2}",Post,Options);  // url:  http://172.20.10.6:8099/user/forgetPassword?userId={1}&passwd={2}  (忘记密码API)
        METHOD_ADD(User::registerInfo, "register?userId={1}&passwd={2}",Post,Options);  // url:  http://172.20.10.6:8099/user/register?userId={1}&passwd={2}   (注册API)
        METHOD_ADD(User::getNitrogenInfo, "nitrogenInfo",Get,Options);              // url:  http://172.20.10.6:8099/user/nitrogenInfo     (氮元素API)
        METHOD_ADD(User::getPhosphorusInfo, "phosphorusInfo",Get,Options);              // url:  http://172.20.10.6:8099/user/phosphorusInfo   (磷元素API)
        METHOD_ADD(User::getPotassiumInfo, "potassiumInfo",Get,Options);              // url:  http://172.20.10.6:8099/user/potassiumInfo     (钾元素API)
        METHOD_ADD(User::getTemperatureInfo, "temperatureInfo",Get,Options);              // url:  http://172.20.10.6:8099/user/temperatureInfo   (温度API)
        METHOD_ADD(User::getHumidityInfo, "humidityInfo",Get,Options);              // url:  http://172.20.10.6:8099/user/humidityInfo       (湿度API)
        METHOD_ADD(User::getPhValueInfo, "phValueInfo",Get,Options);              // url:  http://172.20.10.6:8099/user/phValueInfo         (PH值API)
        METHOD_ADD(User::getErrorInfo, "errorInfo",Get,Options);              // url:  http://172.20.10.6:8099/user/errorInfo        (错误提示API)
    METHOD_LIST_END

    // POST请求函数实现虚函数
    void loginInfo(const HttpRequestPtr &req,
               std::function<void(const HttpResponsePtr &)> &&callback,
               std::string &&userId,
               const std::string &password);

    void forgetPasswordInfo(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   std::string &&userId,
                   const std::string &password);

    void registerInfo(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   std::string &&userId,
                   const std::string &password);

    //GET请求函数实现虚函数
    void getNitrogenInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getPhosphorusInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getPotassiumInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getTemperatureInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getHumidityInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getPhValueInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getErrorInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);
};

