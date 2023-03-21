<template>
  <div>
    <e-charts class="charts" :option="option"/>
  </div>
</template>

<script>
export default {
  data(){
    return{
      data:this.getRandomData(),
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
          data: this.data.map(d => d.time),
        },
        yAxis: {
          type: 'value'
        },
        series: [
          {
            name:'氮含量',
            data: this.data.map(d => d.nitrogenValue),
            type: 'line'
          },
          {
            name:'磷含量',
            data: this.data.map(d => d.phosphorusValue),
            type: 'line'
          },
          {
            name:'钾含量',
            data: this.data.map(d => d.potassiumValue),
            type: 'line'
          }
        ]
      }
    },
  },
  methods:{
    getRandomData(){
      return[
        {
          time:'2023-01-01',
          nitrogenValue:Math.random()*100,
          phosphorusValue:Math.random()*100,
          potassiumValue:Math.random()*100,
        },
        {
          time:'2023-01-02',
          nitrogenValue:Math.random()*100,
          phosphorusValue:Math.random()*100,
          potassiumValue:Math.random()*100,
        },
        {
          time:'2023-01-03',
          nitrogenValue:Math.random()*100,
          phosphorusValue:Math.random()*100,
          potassiumValue:Math.random()*100,
        },
        {
          time:'2023-01-04',
          nitrogenValue:Math.random()*100,
          phosphorusValue:Math.random()*100,
          potassiumValue:Math.random()*100,
        },
        {
          time:'2023-01-05',
          nitrogenValue:Math.random()*100,
          phosphorusValue:Math.random()*100,
          potassiumValue:Math.random()*100,
        },
      ]
    },
  },
  created() {
    setInterval(() => {
      this.data = this.getRandomData();
    },1000)
  }
}
</script>

<style scoped>
.charts{
  height: 220px;
  width: 100%;
}
</style>