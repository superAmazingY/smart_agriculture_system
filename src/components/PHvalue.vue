<template>
  <div id="myCharts" ref="myCharts" style="width: 100%;height: 220px"></div>
</template>

<script>
export default {
  mounted(){
    //使用init初始化
    const  myCharts = this.$echarts.init(this.$refs.myCharts);
    let options = {
      title: {
        text: '酸碱度',   //图表顶部的标题
      },
      tooltip: {   //鼠标悬浮框的提示文字
        trigger: 'axis'
      },
      legend: {
        data:['PH值']
      },
      xAxis : [{  //x轴坐标数据
        type : 'category',
        boundaryGap : false,
        data : ['周一','周二','周三','周四','周五','周六','周日']
      }],
      yAxis : [{   //y轴坐标数据
        type : 'value',
        axisLabel : {
          formatter: '{value}'
        }
      }],
      series: [  //驱动图表生成的数据内容数组，几条折现，数组中就会有几个对应对象，来表示对应的折线
        {
          name:"PH值",
          type: "line",  //pie->饼状图  line->折线图  bar->柱状图
          data:[7, 5, 7.5, 13, 12, 13, 10],
        }
      ]}

    myCharts.setOption(options);
  }

}
</script>

<style scoped>

</style>