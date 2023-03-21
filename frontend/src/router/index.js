import Vue from 'vue'
import VueRouter from 'vue-router'
import home from "../views/Home.vue"
import login from "@/views/Login.vue";
import forgetpwd from "../views/Forgetpwd.vue"
import register from "@/views/Register.vue";
import DataSet from "@/components/DataCenter.vue";
import CommonBody from "@/components/CommonBody.vue";
import Index from "@/components/Index.vue";
import FacilityControl from "@/components/FacilityControl.vue";
import FacilityCenter from "@/components/FacilityCenter.vue";

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
      {path: 'main',component: Index}, //首页
      {path: 'facilityControl',component: FacilityControl},//个人中心
      {path: 'monitoring',component: CommonBody}, //智能监控
      {path: 'facilityCenter',component: FacilityCenter},//设备列表
      {path:'datacenter',component:DataSet}, //数据设置
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
