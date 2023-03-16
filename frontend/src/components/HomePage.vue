//写HTML
<template>
  <div class="body">
    <el-header class="header" >
      <img src="../assets/logo.png" width="50px" height="50px">
      <h3>欢迎来到智慧农业检测系统</h3>
    </el-header>
    <div class="clear"></div>
    <div class="wheather">
      <h4>天气信息</h4>
      <div id="he-plugin-standard"></div>
    </div>
    <div>
      <div class="document-right">
        <div class="document-right-top">
          <h4>系统概览</h4>
          <el-row :gutter="20">
            <el-col :span="6" clss="el-col">
              <div >
                <el-statistic title="用户" >
                  <template slot="formatter" > <span color="green">10</span></template>
                </el-statistic>
              </div>
            </el-col>
            <el-col :span="6">
              <div>
                <el-statistic title="角色">
                  <template slot="formatter"> 6</template>
                </el-statistic>
              </div>
            </el-col>
            <el-col :span="6">
              <div>
                <el-statistic title="设备">
                  <template slot="formatter"> 9</template>
                </el-statistic>
              </div>
            </el-col>

          </el-row>
        </div><hr>
        <div class="document-right-down">
          <h4>设备状态</h4>
          <el-row :gutter="20">
            <el-col :span="6" >
              <div clss="el-col1">
                <el-statistic  title="设备在线状态" >
                  <template slot="formatter" >
                    <span >在线</span>
                  </template>
                </el-statistic>
              </div>
            </el-col>
          </el-row>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  created(){
    window.WIDGET = {
      "CONFIG": {
        "layout": "2",
        "width": 230,
        "height": 270,
        "background": "2",
        "dataColor": "000000",
        "key": "49c92f65b0a84c3c98356dd3d1705736"
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
}
.header{
  border-radius: 2px;
  border:1px  grey;
  width:100%;
  height:100px;
  box-shadow: 0 2px 2px 0 rgba(0, .22, .22, .22);
  text-align: center;
  padding:0px 20px;
  margin-left:5px;
  margin-bottom: 20px;
  float:left;
  img{
    float:left;
    padding:10px 20px;
  }
  h3{
    float:left;
    padding:0px 20px;
    text-align: center;
  }
}
.clear{
  clear: both;
}
.wheather{
  float:left;
  border-radius: 2px;
  margin:auto;
  margin-left:5px;
  border:2px  grey;
  width:25%;
  height:350px;
  padding:0px 20px;
  box-shadow: 0 2px 2px 0 rgba(0, 0, 0, .22);
}
.document-right{
  width:69%;
  border-radius: 2px;
  box-shadow: 0 2px 2px 0 rgba(0, 0, 0, .22);
  border:2px  grey;
  height:350px;
  margin:auto;
  margin-left:5px;
  float:right;
}
.document-right-top{
  padding-top:-10px;
  padding-left: 20px;
  width:70%;
  height:150px;
  border-radius: 2px;
  border:2px  grey;

}
.el-col{
  width:100px;
  height:70px;
  border:1px solid grey;
  background-color:whitesmoke;
  text-align: center;
  border-radius: 4px;
  padding-top:10px;
  margin:0 10px;

}
.document-right-down{
  padding-left: 20px;
  width:70%;
  height:150px;
  border-radius: 2px;
  border:2px  grey;
}
.el-col1{
  width:100px;
  height:70px;
  border:0px solid lightgrey;
  background-color:lightgrey;
  text-align: center;
  border-radius: 4px;
  margin:0 10px;

}
.el-col span{
  color:green;
}
</style>

