<template>
  <div>
    <e-charts class="charts" :option="option"/>
  </div>
</template>

<script>
export default {
  data() {
    return {
      HumidityData:[],
      TemperatureData:[],
      value:true
    }
  },
  computed: {
    option() {
      return {
        title: {
          text: '温湿度',   //图表顶部的标题
          textStyle:{
              color:'#fff'
          },
        },
        tooltip: {   //鼠标悬浮框的提示文字
          trigger: 'axis'
        },
        legend: {
          data: ['温度', '湿度']
        },
        xAxis: {
          type: 'category',
          data: this.TemperatureData.map(d => d.time),
          axisLine:{    //改变坐标数据颜色
            lineStyle:{
              color:"#fff"
            }
          }
        },
        yAxis: {
          type: 'value',
          axisLine:{
            lineStyle:{
              color:"#fff"
            }
          }
        },
        series: [
          {
            name: '温度',
            data: this.TemperatureData.map(d => d.value),
            type: 'line',
            smooth: true ,// 将 smooth 属性设置为 true，即可将折线图替换为曲线图。
            itemStyle:{
                color:'#00f0ff',
            }
          },
          {
            name: '湿度',
            data: this.HumidityData.map(d => d.value),
            type: 'line',
            smooth: true ,// 将 smooth 属性设置为 true，即可将折线图替换为曲线图。
            itemStyle:{
                color:'#ff7800',
            }
          }
        ]
      }
    },
  },
  methods: {
    getHumidityData() {
      this.$axios.get("http://8.130.45.241:8099/user/humidityInfo").then(res=>{
        this.HumidityData = res.data
      })
    },
    getTemperatureData() {
      this.$axios.get("http://8.130.45.241:8099/user/temperatureInfo").then(res=>{
        this.TemperatureData = res.data
      })
    },
  },
  mounted() {
    this.intervalId = setInterval(() => {
      this.getHumidityData();
      this.getTemperatureData();
    }, 1000);
  },
  beforeDestroy() {
    clearInterval(this.intervalId);
  },
}
</script>

<style scoped>
.charts {
  height: 220px;
  width: 100%;
}
</style>