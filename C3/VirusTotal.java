import docking.widgets.EmptyBorderButton;
import generic.continues.RethrowContinuesFactory;
import ghidra.app.plugin.core.instructionsearch.InstructionSearchPlugin;
import ghidra.app.plugin.core.instructionsearch.model.InstructionSearchData.UpdateType;
import ghidra.app.plugin.core.instructionsearch.model.InstructionTableDataObject;
import ghidra.app.plugin.core.instructionsearch.model.InstructionTableModel;
import ghidra.app.plugin.core.instructionsearch.ui.AbstractInstructionTable.OperandState;
import ghidra.app.plugin.core.instructionsearch.ui.InstructionSearchDialog;
import ghidra.app.plugin.core.instructionsearch.ui.InstructionTable;
import ghidra.app.plugin.core.instructionsearch.ui.InstructionTablePanel;
import ghidra.app.plugin.core.instructionsearch.util.InstructionSearchUtils;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.bin.ByteProvider;
import ghidra.app.util.bin.MemoryByteProvider;
import ghidra.app.util.bin.format.pe.*;
import ghidra.app.util.bin.format.pe.PortableExecutable.SectionLayout;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.OperandType;
import ghidra.program.model.mem.Memory;
import ghidra.util.MD5Utilities;
import ghidra.util.Msg;
import org.apache.commons.io.IOUtils;
import resources.ResourceManager;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Observable;
import java.util.HashMap;
import java.util.Map;

class VirusTotal {

    private void OpenBrowser(String URL) {
        if (Desktop.isDesktopSupported()) {
            Desktop desktop = Desktop.getDesktop();
            try {
                desktop.browse(new URI(URL));
            } catch (IOException | URISyntaxException e) {
                popup("Error!");
            }
        } else {
            Runtime runtime = Runtime.getRuntime();
            try {
                runtime.exec("xdg-open " + URL);
            } catch (IOException e) {
                popup("Error encountered while searching VT");
            }
        }
    }
    public static void main(String[] args) {
        String url = "https://www.google.com/";
        OpenBrowser(url);
    }
}