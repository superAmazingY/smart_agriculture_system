<template>
  <div id="app" >
    <router-view></router-view>
  </div>
</template>

<script>
export default {
  name: 'app'
}
</script>

<style lang="less">
html,body,h3 ,p{
  margin: 0;
  padding: 0;
}
el-card {
    border:1px solid transparent;
    //border-radius:15px;
    background-color:rgba(255, 255, 255, 0.1);
    box-shadow: 5px 5px 0 0 rgba(0, 0, 0, 0.2);
}


</style>
