<template>
  <div>
    <el-switch
        v-model="value"
        inactive-text="温湿度传感器"
        style="padding-left: 800px">
    </el-switch>
    <e-charts class="charts" :option="option"/>
  </div>
</template>

<script>
export default {
  data() {
    return {
      data: this.getRandomData(),
      value:true
    }
  },
  computed: {
    option() {
      return {
        title: {
          text: '温湿度',   //图表顶部的标题
        },
        tooltip: {   //鼠标悬浮框的提示文字
          trigger: 'axis'
        },
        legend: {
          data: ['温度', '湿度']
        },
        xAxis: {
          type: 'category',
          data: this.data.map(d => d.time),
        },
        yAxis: {
          type: 'value'
        },
        series: [
          {
            name: '温度',
            data: this.data.map(d => d.temperatureValue),
            type: 'line'
          },
          {
            name: '湿度',
            data: this.data.map(d => d.humidityValue),
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
          temperatureValue: Math.random() * 100,
          humidityValue: Math.random() * 100,
        },
        {
          time: '2023-01-02',
          temperatureValue: Math.random() * 100,
          humidityValue: Math.random() * 100,
        },
        {
          time: '2023-01-03',
          temperatureValue: Math.random() * 100,
          humidityValue: Math.random() * 100,
        },
        {
          time: '2023-01-04',
          temperatureValue: Math.random() * 100,
          humidityValue: Math.random() * 100,
        },
        {
          time: '2023-01-05',
          temperatureValue: Math.random() * 100,
          humidityValue: Math.random() * 100,
        },
      ]
    }
  },
  created() {
    setInterval(() => {
      this.data = this.getRandomData();
    }, 1000)
  }
}
</script>

<style scoped>
.charts {
  height: 220px;
  width: 100%;
}
</style>