import Vue from 'vue'
import Vuetify from 'vuetify'
import Vuex from 'vuex'
import 'vuetify/dist/vuetify.min.css'

import App from './App'
import store from './store'

Vue.config.productionTip = false

Vue.use(Vuex)
Vue.use(Vuetify)

/* eslint-disable no-new */
new Vue({
  store,
  components: { App },
  template: '<App/>'
}).$mount('#app')
