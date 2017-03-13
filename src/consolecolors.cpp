#include <be/core/console.hpp>
#include <be/core/id.hpp>
#include <be/core/lifecycle.hpp>
#include <iostream>

using namespace be;

S get_color_name(LogColor color) {
   switch (color) {
      case LogColor::black:         return "Black";
      case LogColor::red:           return "Red";
      case LogColor::green:         return "Green";
      case LogColor::yellow:        return "Yellow";
      case LogColor::blue:          return "Blue";
      case LogColor::purple:        return "Purple";
      case LogColor::cyan:          return "Cyan";
      case LogColor::gray:          return "Gray";
      case LogColor::dark_gray:     return "Dark Gray";
      case LogColor::bright_red:    return "Bright Red";
      case LogColor::bright_green:  return "Bright Green";
      case LogColor::bright_yellow: return "Bright Yellow";
      case LogColor::bright_blue:   return "Bright Blue";
      case LogColor::bright_purple: return "Bright Purple";
      case LogColor::bright_cyan:   return "Bright Cyan";
      case LogColor::white:         return "White";
      default:                      return "Unknown";
   }
}


///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
   BE_IGNORE2(argc, argv);

   be::CoreInitLifecycle init;

   for (int offset = 0; offset <= 8; offset += 8) {
      for (int fg = 0; fg < 16; ++fg) {
         for (int bg = 0; bg < 8; ++bg) {
            LogColor fgc = static_cast<LogColor>(fg);
            LogColor bgc = static_cast<LogColor>(offset + bg);

            S name = get_color_name(fgc);

            size_t w = 17;

            size_t pre = (w - name.length()) >> 1;
            size_t post = w - name.length() - pre;

            std::cout << setcolor(fgc, bgc) << S(pre, ' ') << name << S(post, ' ');
         }

         std::cout << color::gray << std::endl;
      }
   }

   return 0;
};
