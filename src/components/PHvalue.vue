<template>
  <div>
    <e-charts class="charts" :option="option"/>
  </div>
</template>

<script>
export default {
  data() {
    return {
      data: this.getRandomData(),
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
            type: 'line'
          }
        ]
      }
    },
  },
  methods: {
    getRandomData() {
      return [
        {
          time: '2023-01-01',
          value: Math.random() * 100,
        },
        {
          time: '2023-01-02',
          value: Math.random() * 100,
        },
        {
          time: '2023-01-03',
          value: Math.random() * 100,
        },
        {
          time: '2023-01-04',
          value: Math.random() * 100,
        },
        {
          time: '2023-01-05',
          value: Math.random() * 100,
        },
      ]
    }
  },
  created() {
    setInterval(() => {
      this.data = this.getRandomData();
    }, 2000)
  }
}
</script>

<style scoped>
.charts {
  height: 220px;
  width: 100%;
}
</style>