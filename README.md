# GTerm

## Class GTerm

java.lang.Object  
  java.awt.Component  
    java.awt.Container  
      java.awt.Window  
        java.awt.Frame  
          javax.swing.JFrame  
            GTerm  

public final class GTerm

### This Version:

2021.03.01
GTerm allows you to create a GUI application using System.out.println-like statements.

Version History:

2020.02.29: Original version

2020.03.06: Added \n support for print and println. Added clear.

2020.03.10: Added textField, textArea, setTextInField, getTextInField, addButton support, repaint in clear.

2020.03.15: Does not exit on close; added close, addPasswordField, addList, addElementToList, removeElementFromList, getSelectedElementFromList

2020.03.21: Fixed non-removal in removeElementFromList, addList and addTextArea now has auto-scrollbars

2020.06.01: Lists of String type

2020.07.06: getElementFromList returns value of consistent type. Added getSelectedElementIndexFromList, setFilePath

2020.08.25: Lists replaced with tables (\t formats data in to columns. Supports optional header row.). Added addTable, addRowToTable, clearRowsOfTable, getSelectedRowIndexFromTable, getSelectedRowFromTable. Exceptions thrown from invoked supplied methods are more readable. Added addImageIcon(BufferedImage), showErrorDialog(String), showWarningDialog(String). Title of showMessageDialog(String) says "information" instead of "message" (to match icon). addPasswordField, addTextArea and addTextField now return the text field index.

2021.03.01: Images added in a terminal fashion. addTable uses background set by setBackgroundColor.

### Author:
Gayan Wijesinghe
