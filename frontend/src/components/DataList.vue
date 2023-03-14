<template>
  <el-table
      :data="tableData"
      style="width: 100%"
      max-height="640">
    <el-table-column
        fixed
        prop="date"
        label="创建日期"
        width="150">
    </el-table-column>
    <el-table-column
        prop="name"
        label="操作用户"
        width="120">
    </el-table-column>
    <el-table-column
        prop="crop"
        label="应用信息"
        width="150">
    </el-table-column>
    <el-table-column
        prop="PHvalue"
        label="PH范围"
        width="150">
    </el-table-column>
    <el-table-column
        prop="temperatureValue"
        label="温度范围"
        width="150">
    </el-table-column>
    <el-table-column
        prop="humidity"
        label="湿度范围"
        width="150">
    </el-table-column>
    <el-table-column
        prop="Nvalue"
        label="氮元素范围"
        width="150">
    </el-table-column>
    <el-table-column
        prop="Pvalue"
        label="磷元素范围"
        width="150">
    </el-table-column>
    <el-table-column
        prop="Kvalue"
        label="钾元素范围"
        width="150">
    </el-table-column>
    <el-table-column
        fixed="right"
        label="操作"
        width="150">
      <template slot-scope="scope">
        <el-button
            @click.native.prevent="deleteRow(scope.$index, tableData)"
            type="text"
            size="small">
          移除
        </el-button>
        <el-button type="text" size="small">应用</el-button>
      </template>
    </el-table-column>
  </el-table>
</template>

<script>
export default {
  methods: {
    deleteRow(index, rows) {
      rows.splice(index, 1);
    },
  },
  data() {
    return {
      tableData: [{
        date: '2023-03-10',
        name: '胡图图',
        crop: '小麦',
        PHvalue: '7-8',
        temperatureValue: '55-70',
        humidity: '50-90',
        Nvalue: '42-63',
        Pvalue: '45-80',
        Kvalue: '55-78'
      }]
    }
  }
}
</script>

<style scoped>

</style>