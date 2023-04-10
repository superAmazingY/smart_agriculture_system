<template>
  <div class="body">
    <div class="container">
      <el-card class="header"> 
        <div class="r-content">
          <span class="el-dropdown-link">
              <img class="user" src="../assets/rice.jpg" alt="">
            </span>
        </div>
        <h3 style="color:aliceblue">欢迎来到智慧农业检测系统</h3>
      </el-card>
    </div>
      <div class="clear"></div>
      <!--天气预报-->
    <div class="container">
      <el-card class="wheather">
        <h4 style="color:aliceblue">天气信息</h4>
        <i class="el-icon-sunny"></i>
        <div id="he-plugin-standard" class="bg_color"></div>
      </el-card>
    </div>
    <!--分布-->

    <div class="pic">
      <img src="../assets/cotton.jpg"/>
      <img src="../assets/sesame.jpg"/>
      <img src="../assets/potato.jpg"/>
      <img src="../assets/rice.jpg"/>
    </div>
    <div class="block">
      <el-timeline>
        <el-timeline-item timestamp="春季(3——5月)"  placement="top" >
          <div class="container">
            <el-card>
              <h4 >花生，棉花，大豆，水稻等，冬前育苗、早春移栽的作物包括番茄、彩色辣椒</h4>
            </el-card>
          </div>
        </el-timeline-item>
        <el-timeline-item timestamp="夏季(6——8月)"  placement="top">
          <div class="container">
            <el-card>
              <h4 >早稻，早中稻，芝麻，花生等</h4>
            </el-card>
          </div>
        </el-timeline-item>
        <el-timeline-item timestamp="秋季(9——11月)"  placement="top">
          <div class="container">
            <el-card>
              <h4>小麦，油菜，土豆，甜菜等</h4>
            </el-card>
          </div>
        </el-timeline-item>
        <el-timeline-item timestamp="冬季(12——2月)"   placement="top">
          <div class="container">
            <el-card>
              <h4 >大麦，蚕豆，豌豆，油菜等</h4>
            </el-card>
          </div>
        </el-timeline-item>
      </el-timeline>
    </div>
  </div>
</template>

<script>
export default {
  data(){
    return{ }
    
  },
  created(){
    window.WIDGET = {
      "CONFIG": {
        "layout": "2",
        "width": 300,
        "height": 450,
        "background": "5",
        "dataColor": "000000",
        //"backgroundColor":"#ffffff",
        "key": "83134152765846c9b98243bdf23fa6f1"
      }

    };
    (function (d) {
      var c = d.createElement('link')
      c.rel = 'stylesheet'
      c.href = 'https://widget.qweather.net/standard/static/css/he-standard.css?v=2.0'
      var s = d.createElement('script')
      s.src = 'https://widget.qweather.net/standard/static/js/he-standard-common.js?v=2.0"'
      var sn = d.getElementsByTagName('script')[0]
      sn.parentNode.insertBefore(c, sn)
      sn.parentNode.insertBefore(s, sn)
      s.onload=()=>{
        //自动宽度
        setTimeout(() => {
          document.getElementById("he-plugin-standard").style.width  = "100%";
        }, 100);
      }
    })(document)

  }
};
</script>

<style scoped lang="less">
.body{
  margin:auto;
  text-align: center;
  width: 1490px;
  height:630px;
  background: url(../assets/bg_image.jpg)  no-repeat;
  background-size:cover; 
}
.header{
  margin: 5px;
  height:70px;
  .r-content{
    float:left;
    padding:0 20px;
    text-align: center;
    .user{
      width: 45px;
      height: 45px;
      border-radius: 50%;
    }
  }
  h3{
    float:left;
    padding:9px 20px;
    text-align: center;
    display: inline;
  }
}
.container{
  //background-color: rgba(95, 172, 235, 0.5);
  opacity:1.0;
  .el-card{
    background-color: rgba(11, 124, 216, 0.5);
    border:0;
  }
  h4{
    color:aliceblue;
  }
}
.pic{
  width:15%;
  float: left;
  height:535px;
  margin-left: 25px;
  img{
    width:100%;
    height:25%;
  }
}
.block{
  width:55%;
  padding-right: 0;
  float: right;
}
.clear{
  clear: both;
}
.wheather{
  float:left;
  margin: auto auto auto 5px;
  width:25%;
  height:550px;
  padding:0px 20px;
  background-color: rgba(11, 124, 216, 0.5);
  h4{
    float:left;
    width:25%;
    height:10px;
  }
  i{
    height:10px;
    padding-top:25px;
    float:left;
  }
  .bg_color{
    background-color: rgba(11, 124, 216, 0.5);
  }
}
.document-right{
  width:69%;
  height:520px;
  margin:auto;
  padding:20px;
  float:right;
}
.el-breadcrumb{
    height:30px;
    margin-top:10px;
}
.el-col10{
  width:100px;
  height:70px;
  border:1px solid grey;
  background-color:whitesmoke;
  text-align: center;
  border-radius: 4px;
  padding-top:10px;
  margin:0 10px;
  span{
    color:green;
  }
}
.el-col-right-document{
    width:100px;
    height:80px;
  margin: auto auto auto 10px;
  padding:10px 5px;
    span{
      text-align: center;
      width:50px;
      color:green;
      padding:20px 200px ;
    }
  }
.el-row {
    margin-bottom: 20px;
    &:last-child {
      margin-bottom: 0;
    }
  }
  .el-col {
    border-radius: 0;
  }

  .bg-purple {
    width:300px;
    height:150px;
    margin:10px ;
    text-align: center;
  }
  .bg-purple-light {
    width:300px;
    height:150px;
    margin:10px ;
  }
 
</style>

