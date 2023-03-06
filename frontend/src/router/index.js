import Vue from 'vue'
import VueRouter from 'vue-router'
import home from "../views/Home.vue"
import login from "@/views/Login.vue";
import forgetpwd from "../views/Forgetpwd.vue"
import register from "@/views/Register.vue";

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    redirect:'/home',
  },
  {
    path: '/home',
    name: 'home',
    component: home
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
