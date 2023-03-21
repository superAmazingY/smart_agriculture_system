<template>
  <el-row>
    <el-col :span="8">
      <div class="grid-content bg-purple">
        <el-card class="box-card">
          <div class="user">
            <img alt="" src="../assets/rice.jpg">
            <div class="userinfo">
              <p class="name">智能农业管理</p>
              <p class="access">超级管理员</p>
            </div>
          </div>
          <div class="login-info">
            <p>当前登录日期：<span>{{ time }}</span></p>
            <p>当前登录地点：<span>{{ city }}</span></p>
          </div>
        </el-card>
        <el-card class="box-card" style="height: 355px">
          <template>
            <el-table
                :data="tableData"
                style="width: 100%">
              <el-table-column
                  label="日期"
                  prop="date"
                  width="210">
              </el-table-column>
              <el-table-column
                  label="错误提示"
                  prop="cause"
                  width="190">
              </el-table-column>
            </el-table>
          </template>
        </el-card>
      </div>
    </el-col>
    <el-col :span="16">
      <div class="grid-content bg-purple-light">
        <el-card class="box-card" style="height: 213px">
          <Temperature></Temperature>
        </el-card>
        <el-card class="box-card" style="height: 213px">
          <Azophoska></Azophoska>
        </el-card>
        <el-card class="box-card" style="height: 214px">
          <PHvalue></PHvalue>
        </el-card>
      </div>
    </el-col>
  </el-row>
</template>

<script>
import Temperature from "@/components/Temperature.vue";
import PHvalue from "@/components/PHvalue.vue";
import Azophoska from "@/components/Azophoska.vue";

export default {
  components: {
    Temperature,
    PHvalue,
    Azophoska,
  },
  data() {
    return {
      //后期修改为json数据
      tableData: [{
        date: '2023-01-02',
        cause: 'PH值过高',
      }, {
        date: '2023-01-04',
        cause: '温度过低',
      }, {
        date: '2023-01-05',
        cause: '钾含量过高',
      }, {
        date: '2023-01-07',
        cause: '氮含量过低',
      }, {
        date: '2023-01-07',
        cause: '氮含量过低',
      }, {
        date: '2023-01-07',
        cause: '氮含量过低',
      }],
      time: this.getNowDate(),
      jokes: [],
      city: this.getIPCity(),
    };
  },
  methods: {
    //获取当前系统时间
    getNowDate() {
      const timeOne = new Date()
      const year = timeOne.getFullYear()
      let month = timeOne.getMonth() + 1
      let day = timeOne.getDate()
      month = month < 10 ? '0' + month : month
      day = day < 10 ? '0' + day : day
      return `${year}-${month}-${day}`
    },
    // 获取ip所在城市、区等信息
    getIPCity() {
      const data = {
        key: 'KSPBZ-V5L33-5EM3D-35N5X-DIY66-CRF7J', //密钥
      };
      const url = 'https://apis.map.qq.com/ws/location/v1/ip'; //腾讯地理位置信息接口
      data.output = 'jsonp' // 解决跨域问题
      this.$jsonp(url, data).then((res) => {
        //console.log('IP所在市',res.result.ad_info.city);
        //console.log('ip所属区',res.result.ad_info.district);
        this.city = res.result.ad_info.city + '-' + res.result.ad_info.district
        return this.city;
      })
    },
  },
}
</script>

<style lang="less" scoped>
.user {
  padding-bottom: 20px;
  margin-bottom: 20px;
  border-bottom: 1px solid #ccc;
  display: flex;
  align-items: center;

  img {
    margin-right: 40px;
    width: 150px;
    height: 150px;
    border-radius: 50%;
  }

  .userinfo {
    .name {
      font-size: 32px;
      margin-bottom: 10px;
    }

    .access {
      color: #999999;
    }
  }
}

.login-info {
  p {
    line-height: 28px;
    font-size: 14px;
    color: #999999;

    span {
      color: #666666;
      margin-left: 60px;
    }
  }
}
</style>