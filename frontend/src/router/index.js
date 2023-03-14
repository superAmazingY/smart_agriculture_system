import Vue from 'vue'
import VueRouter from 'vue-router'
import home from "../views/Home.vue"
import login from "@/views/Login.vue";
import forgetpwd from "../views/Forgetpwd.vue"
import register from "@/views/Register.vue";
import DataSet from "@/components/DataSet.vue";
import CommonBody from "@/components/CommonBody.vue";
import HomePage from "@/components/HomePage.vue";
import PersonalCenter from "@/components/PersonalCenter.vue";
import DataList from "@/components/DataList.vue";
import FacilityList from "@/components/FacilityList.vue";
import FacilitySet from "@/components/FacilitySet.vue";

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    redirect:'/login',
  },
  {
    path: '/home',
    name: 'home',
    component: home,
    children:[
      //子路由
      {path: 'main',component: HomePage}, //首页
      {path: 'personal',component: PersonalCenter},//个人中心
      {path:'dataset',component:DataSet}, //数据设置
      {path: 'monitoring',component: CommonBody}, //智能监控
      {path: 'datalist',component: DataList}, //数据列表
      {path: 'facilitylist',component: FacilityList},//设备列表
      {path: 'facilityset' ,component: FacilitySet}, //设备设置
    ],
  },
  {
    path: '/login',
    name: 'login',
    component: login
  },
  {
    path: '/forgetpwd',
    name: 'forgetpwd',
    component: forgetpwd
  },
  {
    path: '/register',
    name: 'register',
    component: register
  }

]

const router = new VueRouter({
  routes
})

export default router
