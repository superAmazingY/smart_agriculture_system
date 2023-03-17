#include "server_api.h"

//登录
void User::loginInfo(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 std::string &&userId,
                 const std::string &password) {
    HttpResponsePtr resp;
    //认证算法，读数据库，验证身份等...
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.user WHERE username = $1 AND password = $2", userId, password);
    auto r = f.get();
    if (r.size() > 0) {
        LOG_DEBUG << "User " << userId << "登陆成功";
        Json::Value ret;
        ret["result"] = "ok";
        ret["data"] = "登录成功";
        ret["token"] = drogon::utils::getUuid(); //生成token
        resp = HttpResponse::newHttpJsonResponse(ret);
    } else {
        LOG_DEBUG << "User " << userId << "尝试登录失败";
        Json::Value ret;
        ret["result"] = "ok";
        ret["data"] = "登录失败";
        resp = HttpResponse::newHttpJsonResponse(ret);
    }
    callback(resp);
}

//忘记密码
void User::forgetPasswordInfo(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     std::string &&userId,
                     const std::string &password) {
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.user WHERE username = $1", userId);
    auto r = f.get();
    if(r.size()>0){
        clientPtr->execSqlAsyncFuture("update public.user set password=$1 where username=$2",password,userId);
            LOG_DEBUG << "User " << userId << "密码修改成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "修改成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
    }else{
        LOG_DEBUG << "User " << userId << "不存在";
        Json::Value ret;
        ret["result"] = "ok";
        ret["data"] = "用户不存在";
        resp = HttpResponse::newHttpJsonResponse(ret);
    }
    callback(resp);
}

//注册
void User::registerInfo(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback,
                              std::string &&userId,
                              const std::string &password) {
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.user WHERE username = $1", userId);
    auto r = f.get();
    if(r.size()>0){
        LOG_DEBUG << "User " << userId << "已存在，无法注册";
        Json::Value ret;
        ret["result"] = "ok";
        ret["data"] = "用户名存在";
        resp = HttpResponse::newHttpJsonResponse(ret);
    }else{
        clientPtr->execSqlAsyncFuture("INSERT INTO public.user(username, password)VALUES ($1, $2)", userId,password);
        LOG_DEBUG << "User " << userId << "注册成功";
        Json::Value ret;
        ret["result"] = "ok";
        ret["data"] = "注册成功";
        resp = HttpResponse::newHttpJsonResponse(ret);
    }
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

