import Vue from 'vue'
import './plugins/axios'
import App from './App.vue'
import router from './router'
import './plugins/element.js'
import './plugins/charts.js'
import store from './store'
import 'echarts'
import ECharts from 'vue-echarts'

Vue.component('ECharts',ECharts)
Vue.config.productionTip = false

new Vue({
  router,
  store,
  render: h => h(App)
}).$mount('#app')
