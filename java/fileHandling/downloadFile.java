import java.io.FileOutputStream;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class FileDownloader {
    public static void main(String[] args) throws Exception {
        // Eingabeaufforderung für die URL der herunterzuladenden Datei
        System.out.print("File URL: ");
        Scanner scanner = new Scanner(System.in);
        String fileUrl = scanner.nextLine();
        scanner.close();

        // Bestimmen des Verzeichnisses, in dem sich das Programm befindet
        String programDirectory = System.getProperty("user.dir");

        // Herunterladen der Datei und Speichern im gleichen Verzeichnis wie das Programm
        URL url = new URL(fileUrl);
        InputStream inputStream = url.openStream();
        String fileName = url.getFile().substring(url.getFile().lastIndexOf('/') + 1);
        Path filePath = Paths.get(programDirectory + "/" + fileName);
        Files.copy(inputStream, filePath);
        inputStream.close();

        System.out.println("File was saved sucessfully: " + filePath);
    }
}
