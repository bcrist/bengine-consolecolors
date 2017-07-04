demo 'd-misc' {
   app 'consolecolors' {
      icon 'icon/bengine.ico',
      limp_src 'src-consolecolors/*.hpp',
      src 'src-consolecolors/*.cpp',
      link_project { 'core', 'core-id' }
   }
}
