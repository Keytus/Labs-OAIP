object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 291
  ClientWidth = 627
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
  object StringGrid1: TStringGrid
    Left = 480
    Top = 0
    Width = 137
    Height = 209
    ColCount = 2
    RowCount = 10
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 162
    Height = 177
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Button1: TButton
    Left = 176
    Top = 8
    Width = 75
    Height = 25
    Caption = #1042#1074#1086#1076
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 39
    Width = 75
    Height = 25
    Caption = #1042#1099#1074#1086#1076
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 176
    Top = 70
    Width = 99
    Height = 25
    Caption = #1057#1073#1072#1083#1072#1085#1089#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 235
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 5
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 96
    Top = 235
    Width = 129
    Height = 21
    TabOrder = 6
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1090#1077#1093#1090
  end
  object Edit2: TEdit
    Left = 96
    Top = 262
    Width = 89
    Height = 21
    TabOrder = 7
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1082#1083#1102#1095
  end
  object Button5: TButton
    Left = 8
    Top = 191
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 8
    OnClick = Button5Click
  end
  object Edit3: TEdit
    Left = 96
    Top = 191
    Width = 89
    Height = 21
    TabOrder = 9
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1082#1083#1102#1095
  end
  object TreeView1: TTreeView
    Left = 322
    Top = 0
    Width = 121
    Height = 209
    Indent = 19
    TabOrder = 10
  end
  object Button6: TButton
    Left = 432
    Top = 240
    Width = 75
    Height = 25
    Caption = #1051#1080#1089#1090#1100#1103
    TabOrder = 11
    OnClick = Button6Click
  end
end
