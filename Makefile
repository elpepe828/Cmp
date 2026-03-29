include $(THEOS)/makefiles/common.mk

TWEAK_NAME = CmpMod

CmpMod_FILES = Tweak.xm src/main.mm
CmpMod_FRAMEWORKS = Foundation IOKit AppKit GameController UIKit
CmpMod_CFLAGS = -fobjc-arc
CmpMod_LDFLAGS = -undefined dynamic_lookup

include $(THEOS)/makefiles/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"

