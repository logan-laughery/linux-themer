const layoutModule = {
  namespaced: true,
  state: {
    selection: undefined
  },
  mutations: {
    updateSelection: (state, payload) => {
      state.selection = payload
    },
    selectDark: (state) => {
      state.selection = 'DARK'
    },
    selectLight: (state) => {
      state.selection = 'LIGHT'
    },
    clearSelection: (state) => {
      state.selection = undefined
    }
  },
  getters: {
    selection: state => state.selection,
    isDarkSelected: (state) => {
      return state.selection === 'DARK'
    },
    isLightSelected: (state) => {
      return state.selection === 'LIGHT'
    }
  }
}

export default layoutModule
