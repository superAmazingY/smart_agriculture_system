#include "server_api.h"

//登录
void User::loginInfo(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 std::string &&userId,
                 const std::string &password) {
    LOG_DEBUG << "User " << userId << " login";
    //认证算法，读数据库，验证身份等...

    Json::Value ret;
    ret["result"] = "ok";
    ret["token"] = drogon::utils::getUuid(); //生成token
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//忘记密码
void User::forgetPasswordInfo(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     std::string &&userId,
                     const std::string &password) {

    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//注册
void User::registerInfo(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback,
                              std::string &&userId,
                              const std::string &password) {

    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//氮含量
void  User::getNitrogenInfo(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback) {
    //验证token有效性等
    //读数据库或缓存获取用户信息
    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//磷含量
void  User::getPhosphorusInfo(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback) {
    //验证token有效性等
    //读数据库或缓存获取用户信息
    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//钾含量
void  User::getPotassiumInfo(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback) {
    //验证token有效性等
    //读数据库或缓存获取用户信息
    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//温度
void  User::getTemperatureInfo(const HttpRequestPtr &req,
                             std::function<void(const HttpResponsePtr &)> &&callback) {
    //验证token有效性等
    //读数据库或缓存获取用户信息
    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//湿度
void  User::getHumidityInfo(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback) {
    //验证token有效性等
    //读数据库或缓存获取用户信息
    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//PH值
void  User::getPhValueInfo(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback) {
    //验证token有效性等
    //读数据库或缓存获取用户信息
    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

//错误信息
void  User::getErrorInfo(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback){
     //验证token有效性等
     //读数据库或缓存获取用户信息
     Json::Value ret;
     ret["result"] = "ok";
     auto resp = HttpResponse::newHttpJsonResponse(ret);
     callback(resp);
}
