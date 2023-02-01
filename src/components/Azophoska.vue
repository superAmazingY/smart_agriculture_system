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
        text: '氮磷钾含量',   //图表顶部的标题
      },
      tooltip: {   //鼠标悬浮框的提示文字
        trigger: 'axis'
      },
      legend: {
        data:['氮含量','磷含量','钾含量']
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
          name:"氮含量",
          type: "line",  //pie->饼状图  line->折线图  bar->柱状图
          data:[11, 11, 15, 13, 12, 13, 10],
        },
        {
          name:"磷含量",
          type: "line",  //pie->饼状图  line->折线图  bar->柱状图
          data:[1, 8, 2, 5, 3, 2, 8],
        },
        {
          name:"钾含量",
          type: "line",  //pie->饼状图  line->折线图  bar->柱状图
          data:[2, 5, 9, 8, 0, 4, 7],
        }
      ]}

    myCharts.setOption(options);
  }

}
</script>

<style scoped>

</style>