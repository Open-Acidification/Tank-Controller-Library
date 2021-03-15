#include "UIState.h"

#include "../TankControllerLib.h"
#include "UIState/MainMenu.h"

void UIState::setNextState(UIState* state) {
  std::cout << __FILE__ << ":" << __LINE__ << std::endl;
  tc->setNextState(state);
  std::cout << __FILE__ << ":" << __LINE__ << std::endl;
}

void UIState::returnToMainMenu() {
  std::cout << __FILE__ << ":" << __LINE__ << std::endl;
  setNextState((UIState*)new MainMenu(tc));
  std::cout << __FILE__ << ":" << __LINE__ << std::endl;
}
