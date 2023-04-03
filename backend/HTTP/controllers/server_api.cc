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
    try {
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
    }catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//忘记密码
void User::forgetPasswordInfo(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     std::string &&userId,
                     const std::string &password) {
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.user WHERE username = $1", userId);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            clientPtr->execSqlAsyncFuture("update public.user set password=$1 where username=$2", password, userId);
            LOG_DEBUG << "User " << userId << "密码修改成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "修改成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            LOG_DEBUG << "User " << userId << "不存在";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "用户不存在";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    }catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//注册
void User::registerInfo(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback,
                              std::string &&userId,
                              const std::string &password) {
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.user WHERE username = $1", userId);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            LOG_DEBUG << "User " << userId << "已存在，无法注册";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "用户名存在";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            clientPtr->execSqlAsyncFuture("INSERT INTO public.user(username, password)VALUES ($1, $2)", userId,
                                          password);
            LOG_DEBUG << "User " << userId << "注册成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "注册成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    }catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}


//氮含量
void  User::getNitrogenInfo(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.n_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//磷含量
void  User::getPhosphorusInfo(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.p_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//钾含量
void  User::getPotassiumInfo(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.k_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//温度
void  User::getTemperatureInfo(const HttpRequestPtr &req,
                             std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.temperature_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//湿度
void  User::getHumidityInfo(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.humidity_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//PH值
void User::getPhValueInfo(const HttpRequestPtr &req,
                          std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.ph_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}



//错误信息
void  User::getErrorInfo(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback){
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.error_value");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//数据中心
void  User::getDataCenter(const HttpRequestPtr &req,
                         std::function<void(const HttpResponsePtr &)> &&callback){
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.datacenter_value");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["name"] = row["name"].as<std::string>();
                obj["ph_value"] = row["ph_value"].as<std::string>();
                obj["temperature_value"] = row["temperature_value"].as<std::string>();
                obj["humidity_value"] = row["humidity_value"].as<std::string>();
                obj["n_value"] = row["n_value"].as<std::string>();
                obj["p_value"] = row["p_value"].as<std::string>();
                obj["k_value"] = row["k_value"].as<std::string>();
                obj["time"] = row["time"].as<std::string>();
                result.append(obj);
            }
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//设备中心
void  User::getFacilityCenter(const HttpRequestPtr &req,
                         std::function<void(const HttpResponsePtr &)> &&callback){
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.facilitycenter_value");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["name"] = row["name"].as<std::string>();
                obj["info"] = row["info"].as<std::string>();
                obj["number"] = row["number"].as<std::string>();
                obj["time"] = row["time"].as<std::string>();
                result.append(obj);
            }
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

