
from javax.swing import JFrame, JTable, JScrollPane
from java.awt import Dimension

def displayTable(headers, data):
    # Create the JFrame
    frame = JFrame("Functions with Strings")
    frame.setSize(400, 300)

    # Create the JTable
    table = JTable(data, headers)

    # Add the JTable to a JScrollPane
    scrollPane = JScrollPane(table)

    # Add the JScrollPane to the JFrame
    frame.add(scrollPane)

    # Set the size of the JFrame
    frame.setPreferredSize(Dimension(400, 300))

    # Display the JFrame
    frame.pack()
    frame.setVisible(True)
