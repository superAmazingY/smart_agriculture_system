#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class User : public drogon::HttpController<User> {
public:
    METHOD_LIST_BEGIN
        // use METHOD_ADD to add your custom processing function here;
        METHOD_ADD(User::loginInfo, "login?userId={1}&passwd={2}",Post,Options);
    // url:  http://8.130.45.241:8099/user/login?userId={1}&passwd={2}(登录API)
        METHOD_ADD(User::forgetPasswordInfo, "forgetPassword?userId={1}&passwd={2}",Post,Options);
        // url:  http://8.130.45.241:8099/user/forgetPassword?userId={1}&passwd={2}(忘记密码API)
        METHOD_ADD(User::registerInfo, "register?userId={1}&passwd={2}",Post,Options);
        // url:  http://8.130.45.241:8099/user/register?userId={1}&passwd={2}(注册API)
        METHOD_ADD(User::getNitrogenInfo, "nitrogenInfo",Get,Options);
        // url:  http://8.130.45.241:8099/user/nitrogenInfo(氮元素API)
        METHOD_ADD(User::getPhosphorusInfo, "phosphorusInfo",Get,Options);
        // url:  http://8.130.45.241:8099/user/phosphorusInfo(磷元素API)
        METHOD_ADD(User::getPotassiumInfo, "potassiumInfo",Get,Options);
        // url:  http://8.130.45.241:8099/user/potassiumInfo(钾元素API)
        METHOD_ADD(User::getTemperatureInfo, "temperatureInfo",Get,Options);
        // url:  http://8.130.45.241:8099/user/temperatureInfo(温度API)
        METHOD_ADD(User::getHumidityInfo, "humidityInfo",Get,Options);
        // url:  http://8.130.45.241:8099/user/humidityInfo(湿度API)
        METHOD_ADD(User::getPhValueInfo, "phValueInfo",Get,Options);
        // url:  http://8.130.45.241:8099/user/phValueInfo(PH值API)
        METHOD_ADD(User::getErrorInfo, "errorInfo",Get,Options);
        // url:  http://8.130.45.241:8099/user/errorInfo(错误提示API)
        METHOD_ADD(User::getDataCenter, "datacenter",Get,Options);
        // url:  http://8.130.45.241:8099/user/datacenter(数据中心API)
        METHOD_ADD(User::getFacilityCenter, "facility",Get,Options);
        // url:  http://8.130.45.241:8099/user/facility(设备中心API)
        METHOD_ADD(User::getCenterData, "getCenterData?name={1}&ph={2}&temperature={3}&humidity={4}&N={5}&P={6}&K={7}&date={8}",Post,Options);
        // url:  http://8.130.45.241:8099/user/getCenterData?name={1}&ph={2}&temperature={3}&humidity={4}&N={5}&P={6}&K={7}&date={8}(添加数据中心API)
        METHOD_ADD(User::getFacilityData, "getFacilityData?name={1}&info={2}&number={3}&date={4}",Post,Options);
        //url: http://8.130.45.241:8099/user/getFacilityData?name={1}&info={2}&num={3}&date={4}(添加设备中心API)
        METHOD_ADD(User::deleteFacilityCenter, "deleteFacilityData?name={1}",Post,Options);
        //url: http://8.130.45.241:8099/user/deleteFacilityData?name={1}(删除设备中心API)
        METHOD_ADD(User::deleteCenterData, "deleteCenterData?name={1}",Post,Options);
        //url: http://8.130.45.241:8099/user/deleteCenterData?name={1}(删除设备中心API)
        METHOD_ADD(User::editFacilityCenter, "editFacilityData?oldname={1}&newname={2}&info={3}&num={4}&date={5}", Post, Options);
        // URL: http://8.130.45.241:8099/user/editFacilityData?oldname={1}&newname={2}&info={3}&num={4}&date={5} (编辑设备中心API)
        METHOD_ADD(User::editCenterData, "editCenterData?oldname={1}&newname={2}&ph={3}&temperature={4}&humidity={5}&N={6}&P={7}&K={8}&date={9}", Post, Options);
        // URL: http://8.130.45.241:8099/user/editCenterData?oldname={1}&newname={2}&ph={3}&temperature={4}&humidity={5}&N={6}&P={7}&K={8}&date={9} (编辑数据中心API)

    METHOD_LIST_END

    // POST请求函数实现虚函数
    void loginInfo(const HttpRequestPtr &req,
               std::function<void(const HttpResponsePtr &)> &&callback,
               std::string &&userId,
               const std::string &password);

    void deleteFacilityCenter(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   const std::string &name);

    void deleteCenterData(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback,
                              const std::string &name);

    void forgetPasswordInfo(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   std::string &&userId,
                   const std::string &password);

    void registerInfo(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   std::string &&userId,
                   const std::string &password);

    void getCenterData(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback,
                  const std::string &name,const std::string &ph,const std::string &temperature,
                  const std::string &humidity,const std::string &N,const std::string &P,const std::string &K,const std::string &date);

    void getFacilityData(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback,
                       const std::string &name,const std::string &info,const std::string &num,const std::string &date);

    void editCenterData(const HttpRequestPtr &req,
                        std::function<void(const HttpResponsePtr &)> &&callback,
                        const std::string &oldname,
                        const std::string &newname,const std::string &ph,const std::string &temperature,
                        const std::string &humidity,const std::string &N,const std::string &P,const std::string &K,const std::string &date);

    void editFacilityCenter(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback,
                            const std::string &oldname,
                            const std::string &newname,const std::string &info,const std::string &num,const std::string &date);


    //GET请求函数实现虚函数
    void getNitrogenInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getPhosphorusInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getPotassiumInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getTemperatureInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getHumidityInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getPhValueInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getErrorInfo(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getDataCenter(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);

    void getFacilityCenter(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback);
};

