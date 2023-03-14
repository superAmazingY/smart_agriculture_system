<template>
  <el-card class="box-card">
    <el-form ref="form" :model="form" label-width="100px">
      <el-form-item label="农作物信息">
        <el-input v-model="form.name"></el-input>
      </el-form-item>
      <hr>
      <p class="commonP">PH范围</p>
      <template>
        <el-input-number v-model="form.phminnum" :min="1" :max="10" label="PH下限"></el-input-number>
      </template>
      ---
      <template>
        <el-input-number v-model="form.phmaxnum" :min="1" :max="14" label="PH下限"></el-input-number>
      </template>
      <hr>
      <p class="commonP">温度范围</p>
      <template>
        <el-input-number v-model="form.temminnum" :min="1" :max="50" label="温度下限"></el-input-number>
      </template>
      ---
      <template>
        <el-input-number v-model="form.temmaxnum" :min="1" :max="100" label="温度下限"></el-input-number>
      </template>
      <hr>
      <p class="commonP">湿度范围</p>
      <template>
        <el-input-number v-model="form.humminnum" :min="1" :max="50" label="湿度下限"></el-input-number>
      </template>
      ---
      <template>
        <el-input-number v-model="form.hummaxnum" :min="1" :max="100" label="湿度下限"></el-input-number>
      </template>
      <hr>
      <p class="commonP">氮含量范围</p>
      <template>
        <el-input-number v-model="form.Nminnum" :min="1" :max="50" label="氮下限"></el-input-number>
      </template>
      ---
      <template>
        <el-input-number v-model="form.Nmaxnum" :min="1" :max="100" label="氮下限"></el-input-number>
      </template>
      <hr>
      <p class="commonP">磷含量范围</p>
      <template>
        <el-input-number v-model="form.Pminnum"  :min="1" :max="50" label="磷下限"></el-input-number>
      </template>
      ---
      <template>
        <el-input-number v-model="form.Pmaxnum"  :min="1" :max="100" label="磷下限"></el-input-number>
      </template>
      <hr>
      <p class="commonP">钾含量范围</p>
      <template>
        <el-input-number v-model="form.Kminnum"  :min="1" :max="50" label="钾下限"></el-input-number>
      </template>
      ---
      <template>
        <el-input-number v-model="form.Kmaxnum"  :min="1" :max="100" label="钾下限"></el-input-number>
      </template>
      <hr>
    </el-form>
    <el-button type="primary" round >提交</el-button>
  </el-card>
</template>

<script>
export default {
  data(){
    return{
        form: {
          name:'',
          phminnum: 7,
          phmaxnum:10,
          temminnum:20,
          temmaxnum:30,
          humminnum:10,
          hummaxnum:20,
          Nminnum:20,
          Nmaxnum:60,
          Pminnum:60,
          Pmaxnum:60,
          Kminnum:60,
          Kmaxnum:60,
        },
      }
    },
 }
</script>

<style scoped lang="less">
.box-card {
  width: 800px;
  .commonP{
    float: left;
    padding-right: 100px;
    font-size: 14px;
    color: #606266;
    text-align: center;
    padding-left: 18px;
    padding-top: 10px;
  }

}
</style>