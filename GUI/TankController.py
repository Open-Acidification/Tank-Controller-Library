#!python3
import libTC
print('TankController version ', libTC.version())

try:
    import wx
    import wx.Grid as grid
except ImportError:
    print('wxpython is not installed')
    exit()

class TankController(wx.Frame):
  labels = ['1', '2', '3', 'A',
            '4', '5', '6', 'B',
            '7', '8', '9', 'C',
            '*', '0', '#', 'D']
  def __init__(self, parent, title):
    super(TankController, self).__init__(parent, title = title, size = (800,600))
    self.InitUI()
    self.Centre()
    self.Show()

  def InitUI(self):
    panel = wx.Panel(self)
    panel.Bind(wx.EVT_CHAR, self.Keyboard)

    mainSizer = wx.BoxSizer(wx.HORIZONTAL)

    version = wx.StaticText(panel, label="Version " + libTC.version())
    mainSizer.Add(version,1)

    lqdSizer = wx.StaticBoxSizer(wx.VERTICAL, panel)
    self.lqd = wx.StaticText(panel, label = libTC.lcd(0) + '\n' + libTC.lcd(1))
    font = wx.Font(20, wx.FONTFAMILY_TELETYPE, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL)
    self.lqd.SetFont(font)
    lqdSizer.Add(self.lqd, 1)
    mainSizer.Add(lqdSizer,1)

    keypadSizer = wx.StaticBoxSizer(wx.VERTICAL, panel)

    keypadGrid = wx.GridSizer(4, 4, 5, 5)
    for each in self.labels:
      button = wx.Button(panel, label = each)
      button.Bind(wx.EVT_LEFT_UP, self.KeypadEvent)
      keypadGrid.Add(button, 0, wx.EXPAND)
    keypadSizer.Add(keypadGrid, 1)
    mainSizer.Add(keypadSizer, 2)

    addEEPROM(panel, mainSizer)

    panel.SetSizer(mainSizer)

  # getPH();
  # getTemp();
  # getTankID();
  # getCorrectedTemp();
  # getKP();
  # getKI();
  # getKD();
  # getMac();  // See issue #57 about this function
  # getHeat();
  # getAmplitude();
  # getFrequency();
  # getGranularity();
  # getMaxDataAge();
  # getPHSeriesSize();
  # getPHSeriesPointer();
  # getTempSeriesSize();
  # getTempSeriesPointer();
  # getPHInterval();
  # getPHDelay();
  # getTempInterval();
  # getTempDelay();

  def addEEPEOM(self, panel, mainSizer):
    eepromSizer = wx.StaticBoxSizer(wx.VERTICAL, panel, label="EEPROM")
    label = wx.StaticText(panel, label = "PH")
    eepromSizer.Add(label, 1)
    mainSizer.Add(eepromSizer, 3)

  def KeypadEvent(self, event):
    key = event.GetEventObject().GetLabel()
    libTC.key(key)
    libTC.loop()
    self.lqd.SetLabelText(libTC.lcd(0) + '\n' + libTC.lcd(1))
    print("Keypad", key)

  def Keyboard(self, event):
    key = chr(event.GetUnicodeKey()).upper()
    print("Keyboard", key)

app = wx.App()
TankController(None, title = 'Tank Controller')
app.MainLoop()
