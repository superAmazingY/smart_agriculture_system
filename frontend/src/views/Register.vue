<template>
  <div class="register">
    <div class="myregister" align="center">
      <h4>注册</h4>
      <el-form
          :model="registerForm"
          :rules="registerRules"
          ref="forgetpwdForm"
          label-width="0px"
      >
        <el-form-item label="" prop="account" style="margin-top: 10px">
          <el-row>
            <el-col :span="2">
              <span class="el-icon-s-custom"></span>
            </el-col>
            <el-col :span="22">
              <el-input
                  class="inps"
                  placeholder="账号"
                  v-model="registerForm.account"
              >
              </el-input>
            </el-col>
          </el-row>
        </el-form-item>
        <el-form-item label="" prop="passWord">
          <el-row>
            <el-col :span="2">
              <span class="el-icon-lock"></span>
            </el-col>
            <el-col :span="22">
              <el-input
                  class="inps"
                  type="password"
                  placeholder="密码"
                  v-model="registerForm.passWord"
              ></el-input>
            </el-col>
          </el-row>
        </el-form-item>
        <el-form-item label="" prop="confirmPassword" style="margin-top: 10px">
          <el-row>
            <el-col :span="2">
              <span class="el-icon-lock"></span>
            </el-col>
            <el-col :span="22">
              <el-input
                  class="inps"
                  type="password"
                  placeholder="确认密码"
                  v-model="registerForm.confirmPassword"
              >
              </el-input>
            </el-col>
          </el-row>
        </el-form-item>
        <el-form-item style="margin-top: 55px">
          <el-button type="primary" round class="submitBtn" @click="submitForm">注册</el-button>
        </el-form-item>
      </el-form>
    </div>
  </div>
</template>


<script>

export default {
  data: function () {
    return {
      registerForm: {
        account: "",
        passWord: "",
        confirmPassword:'',
      },
      registerRules: {
        account: [{ required: true, message: "请输入账号", trigger: "blur" }],
        passWord: [{ required: true, message: "请输入密码", trigger: "blur" }],
        confirmPassword: [{ required: true, message: "请确认密码", trigger: "blur" }],
      },
    };
  },

  methods: {
    submitForm() {
      const userAccount = this.registerForm.account;
      const userPassword = this.registerForm.passWord
      const userconfirmPassword = this.registerForm.confirmPassword;
      if (!userAccount) {
        return this.$message({
          type: "error",
          message: "账号不能为空！",
        });
      }
      if (!userPassword) {
        return this.$message({
          type: "error",
          message: "密码不能为空！",
        });
      }
      if (!userconfirmPassword) {
        return this.$message({
          type: "error",
          message: "确认密码不能为空！",
        });
      }
      if (userPassword !== userconfirmPassword) {
        return this.$message({
          type: "error",
          message: "两次密码不一致",
        });
      }
      this.$axios.post(`http://8.130.45.241:8099/user/register?userId=${userAccount}&passwd=${userPassword}`,{
      }).then(res=>{
        console.log(res);
        if(res.data.data === "注册成功"){
          this.$router.push({
            path:'/login'
          });
          return this.$message({
            type:"success",
            message:"注册成功请登录",
          })
        }else if(res.data.data === "用户名存在"){
          return this.$message({
            type:"error",
            message:"注册失败，以存在该用户名",
          })
        }else{
          return this.$message({
            type:"error",
            message:"注册失败请再次尝试"
          })
        }
      })
    },
  },
};
</script>


<style scoped lang="less">
.register {
  width: 100vw;
  padding: 0;
  margin: 0;
  height: 100vh;
  font-size: 16px;
  background-position: left top;
  background-color: #242645;
  color: #fff;
  position: relative;
  .myregister {
    width: 240px;
    height: 300px;
    position: absolute;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    margin: auto;
    padding: 50px 40px 40px 40px;
    box-shadow: -15px 15px 15px rgba(6, 17, 47, 0.7);
    opacity: 1;
    background: linear-gradient(
        230deg,
        rgba(53, 57, 74, 0) 0%,
        rgb(0, 0, 0) 100%
    );
  }
}

.inps input {
  border: none;
  color: #fff;
  background-color: transparent;
  font-size: 12px;
}

.submitBtn {
  background-color: transparent;
  color: #39f;
  width: 200px;
}
</style>