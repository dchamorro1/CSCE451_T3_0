import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import java.io.IOException;


class VirusTotal2 {


    public static void main(String[] args) {
        OkHttpClient client = new OkHttpClient();

        Request request = new Request.Builder()
                .url("https://www.virustotal.com/api/v3/files")
                .post(null)
                .addHeader("accept", "application/json")
                .addHeader("x-apikey", "6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a")
                .addHeader("content-type", "multipart/form-data")
                .build();

        Response response = client.newCall(request).execute();

        System.out.println(response.body().string());
    }
}