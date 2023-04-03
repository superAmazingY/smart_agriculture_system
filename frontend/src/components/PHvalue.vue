<template>
  <div>
    <e-charts :option="option" class="charts"/>
  </div>
</template>

<script>
export default {
  data() {
    return {
      data: [],
      value: true
    }
  },
  computed: {
    option() {
      return {
        title: {
          text: '酸碱度',   //图表顶部的标题
        },
        tooltip: {   //鼠标悬浮框的提示文字
          trigger: 'axis'
        },
        legend: {
          data: ['PH值']
        },
        xAxis: { //x轴坐标数据
          type: 'category',
          data: this.data.map(d => d.time),
        },
        yAxis: { //y轴坐标数据
          type: 'value'
        },
        series: [  //驱动图表生成的数据内容数组，几条折现，数组中就会有几个对应对象，来表示对应的折线
          {
            name: 'PH值',
            data: this.data.map(d => d.value),
            type: 'line',
            smooth: true // 将 smooth 属性设置为 true，即可将折线图替换为曲线图。
          }
        ]
      }
    },
  },
  methods: {
    getPhData() {
      this.$axios.get("http://8.130.45.241:8099/user/phValueInfo").then(res => {
        this.data = res.data
      })
    }
  },
  mounted() {
    this.intervalId = setInterval(() => {
      this.getPhData();
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