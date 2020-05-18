object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 291
  ClientWidth = 645
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 0
    Top = 0
    Width = 169
    Height = 185
    ItemHeight = 13
    TabOrder = 0
  end
  object Button1: TButton
    Left = 287
    Top = 8
    Width = 75
    Height = 25
    Caption = #1042#1074#1086#1076
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 287
    Top = 39
    Width = 75
    Height = 25
    Caption = #1042#1099#1074#1086#1076
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 191
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' 1-'#1099#1081
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 231
    Width = 123
    Height = 25
    Caption = #1055#1088#1086#1074#1077#1088#1082#1072' '#1085#1072' '#1087#1091#1089#1090#1086#1090#1091
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 103
    Top = 191
    Width = 99
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1086#1095#1077#1088#1077#1076#1100
    TabOrder = 5
    OnClick = Button5Click
  end
  object StringGrid1: TStringGrid
    Left = 184
    Top = 0
    Width = 81
    Height = 169
    ColCount = 1
    FixedCols = 0
    RowCount = 6
    TabOrder = 6
  end
  object ListBox2: TListBox
    Left = 504
    Top = 0
    Width = 137
    Height = 185
    Columns = 1
    ItemHeight = 13
    TabOrder = 7
  end
  object StringGrid2: TStringGrid
    Left = 400
    Top = 0
    Width = 81
    Height = 169
    ColCount = 1
    FixedCols = 0
    RowCount = 10
    TabOrder = 8
  end
  object Button6: TButton
    Left = 504
    Top = 207
    Width = 75
    Height = 25
    Caption = #1056#1072#1079#1076#1077#1083#1080#1090#1100
    TabOrder = 9
    OnClick = Button6Click
  end
end
