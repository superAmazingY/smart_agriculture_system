<template>
  <div >
    <e-charts class="charts" :option="option"/>
  </div>
</template>

<script>
export default {
  data(){
    return{
      Ndata:[],
      Pdata:[],
      Kdata:[],
      value1:true
    }
  },
  computed:{
    option(){
      return{
        title: {
          text: '氮磷钾含量',   //图表顶部的标题
        },
        tooltip: {   //鼠标悬浮框的提示文字
          trigger: 'axis'
        },
        legend: {
          data:['氮含量','磷含量','钾含量']
        },
        xAxis: {
          type: 'category',
          data: this.Ndata.map(d => d.time),
        },
        yAxis: {
          type: 'value'
        },
        series: [
          {
            name:'氮含量',
            data: this.Ndata.map(d => d.value),
            type: 'line',
            smooth: true // 将 smooth 属性设置为 true，即可将折线图替换为曲线图。
          },
          {
            name:'磷含量',
            data: this.Pdata.map(d => d.value),
            type: 'line',
            smooth: true // 将 smooth 属性设置为 true，即可将折线图替换为曲线图。
          },
          {
            name:'钾含量',
            data: this.Kdata.map(d => d.value),
            type: 'line',
            smooth: true // 将 smooth 属性设置为 true，即可将折线图替换为曲线图。
          }
        ]
      }
    },
  },
  methods:{
    getNData() {
      this.$axios.get("http://8.130.45.241:8099/user/nitrogenInfo").then(res=>{
        this.Ndata = res.data
      })
    },
    getPData() {
      this.$axios.get("http://8.130.45.241:8099/user/phosphorusInfo").then(res=>{
        this.Pdata = res.data
      })
    },
    getKData() {
      this.$axios.get("http://8.130.45.241:8099/user/potassiumInfo").then(res=>{
        this.Kdata = res.data
      })
    },
  },
  mounted() {
    this.intervalId = setInterval(() => {
      this.getKData();
      this.getPData();
      this.getNData()
    }, 1000);
  },
  beforeDestroy() {
    clearInterval(this.intervalId);
  },
}
</script>

<style scoped>
.charts{
  height: 220px;
  width: 100%;
}
</style>