<template>
  <div class="body">
    <el-card class="header">
      <el-form :inline="true" :model="brand">
        <el-form-item label="设备名称">
          <el-input v-model="brand.equipmentName" aria-placeholder="设备名称" class="el-input_inner"></el-input>
        </el-form-item>
        <el-form-item label="设备概述">
          <el-input v-model="brand.equipmentView" aria-placeholder="设备概述" class="el-input_inner"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary" @click="onSubmit" class="el-button">搜索</el-button >
          <el-button icon="el-icon-delete" type="primary" @click="clearButton" class="el-button"></el-button>
        </el-form-item>
      </el-form>
      <!-- <span>设备名称<el-input v-model="input1" class="el-input_inner" placeholder="请输入内容"></el-input></span> -->
      <!-- <span>设备详情<el-input v-model="input2" class="el-input_inner" placeholder="请输入内容"></el-input></span> -->
      <!-- <el-button class="el-button" icon="el-icon-search" type="primary" >搜索</el-button> -->
      
    </el-card>
    <el-card>
      <el-table :data="tableData.filter(data => !search || data.name.toLowerCase().includes(search.toLowerCase()))"
                height="470" style="width: 100%">
        <el-table-column label="序号" prop="id"  width="100"></el-table-column>
        <el-table-column label="设备名称" prop="name" width="150"></el-table-column>
        <el-table-column label="设备概述" prop="address" width="600"></el-table-column>
        <el-table-column label="数量" prop="number" width="100"></el-table-column>
        <el-table-column label="添加时间" prop="date" width="150"></el-table-column>
        <el-table-column align="right">
          <template slot="header">
            <el-row>
              <el-button type="primary" plain @click="dialogVisible=true">添加设备</el-button>
            </el-row>
          </template>
          <template>
            <el-button size="mini" @click.native="handleEdit" type="primary">编辑</el-button>
            <el-button size="mini" type="danger" @click="handleDelete">删除</el-button>
          </template>
        </el-table-column>
      </el-table>
    </el-card>

    <el-dialog
        title="添加设备"
        :visible.sync="dialogVisible"
        width="40%"
    >
      <el-form :label-position="labelPosition" label-width="80px" :model="formLabelAlign">
        <el-form-item label="设备名称">
          <el-input v-model="formLabelAlign.name"></el-input>
        </el-form-item>
        <el-form-item label="设备概述">
          <el-input v-model="formLabelAlign.address"></el-input>
        </el-form-item>
        <el-form-item label="数量">
          <el-input v-model="formLabelAlign.number"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary" @click="addBrand">立即创建</el-button>
          <el-button @click="dialogVisible=false">取消</el-button>
        </el-form-item>
      </el-form>
    </el-dialog>

  </div>
</template>

<script>
export default {
  data() {
    return {
      input1: '',
      input2: '',
      dialogVisible: false,

      //弹窗的表单内容
      labelPosition: 'right',
      formLabelAlign: {
        name: '',
        address: '',
        number: '',
      },
      //搜索
      brand:{
        equipmentName:'',
        equipmentView:''
      },
      multipleSelection:[],
      tableData: [{
        id: '1',
        date: '2023-03-19',
        name: '树莓派终端',
        address: '树莓派是由树莓派基金会研发的一种只有信用卡大小的单板机电脑，最初的设计目标是用较为廉价的硬件和开源软件为儿童提供一个计算机教育平台。但其优秀的扩展性和易于开发的特性，使其不仅仅用于儿童教育，更是成为了极客们的玩具。树莓派被开发出了千千万万种玩法，并且普通人也可以轻松实现。',
        number:  1,
      }, {
        id: '2',
        date: '2023-03-19',
        name: 'RS485 NPK传感器',
        address: 'NPK传感器设计用于检测土壤中氮、磷、钾的含量，确定土壤的肥力，方便客户系统对土壤状况进行评估。',
        number: 1,
      }, {
        id: '3',
        date: '2023-03-19',
        name: 'RS485 温湿度PH传感器',
        address: '温湿度传感器多以温湿度一体式的探头作为测温元件，将温度和湿度信号采集出来，经过稳压滤波、运算放大、非线性校正、V/I转换、恒流及反向保护等电路处理后，转换成与温度和湿度成线性关系的电流信号或电压信号输出，也可以直接通过主控芯片进行485或232等接口输出。',
        number: 1,
      }],
      search: ''
    }
  },
  methods: {
    handleEdit(){

    },
    handleDelete(){

    },
    //搜索按钮
    onSubmit(){
      console.log(this.brand);
    },
    //提交按钮
    addBrand(){
      console.log(this.formLabelAlign);
    },
    clearButton(){
      this.input1 = '';
      this.input2 = '';
    }
  }
}
</script >

<style lang="less" scoped>
.body{
  margin:auto;
  text-align: center;
}
.header {
  margin: auto;
  height:110px;
  width: 100%;
  .el-input_inner {
    width: 300px;
   padding: 5px 15px;
   float: left;
  }
}

.el-button {
  margin: 5px 14px 14px 40px;
  width: 100px;
  //padding-left: 20px;
  height: 40px;
  float: left;
}
</style>