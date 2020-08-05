import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Scanner;

public class Attendance {

    Scanner scan = new Scanner(System.in);
    static HashMap<String, String> map = new HashMap<>();
    private String username;
    private String password;
    static boolean circulation = true;
    SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    String format = df.format(new Date());
    String time = format.substring(11, 13);
    public Attendance() {
    }

    public Attendance(String username, String password) {
        this.username = username;
        this.password = password;
        map.put(username,password);
    }

    public void opera(){

        while(true) {
            System.out.println("-------------------------------------------------------");
            System.out.println("请选择功能      1.(注册)    2.(登陆)");
            System.out.println("-------------------------------------------------------");

            int option = 0;
            boolean b = true;
            while (b){
                try {
                    option = scan.nextInt();
                    b = false;
                } catch (Exception e) {
                    System.out.println("输入错误，请重新输入!");
                    scan.nextLine();
                }
            }

            switch (option) {
                case 1:
                    reg();
                    circulation = true;
                    while (circulation) {
                        menu();
                    }
                    break;
                case 2:
                    login();
                    circulation = true;
                    while (circulation) {
                        menu();
                    }
                    break;
                default:
                    System.out.println("你的选择有误,请重新输入");
            }
        }

    }
    public void menu(){

        System.out.println("-------------------------------------------------------");
        System.out.println("                 1——上班签到");
        System.out.println("                 2——下班签出");
        System.out.println("                 3——考勤信息查阅");
        System.out.println("                 4——退出");
        System.out.println("-------------------------------------------------------");
        int choice = 0;
        boolean b = true;
        while (b){
            try {
                choice = scan.nextInt();
                b = false;
            } catch (Exception e) {
                System.out.println("输入错误，请重新输入!");
                scan.nextLine();
            }
        }
        switch(choice){
            case 1:
                check_in();
                break;
            case 2:
                check_out();
                break;
            case 3:
                display_record();
                break;
            case 4:
                System.out.println(username+"用户已退出！");
                circulation = false;
                break;
            default:
                System.out.println("输入错误！");
        }
    }
    public void login(){
        boolean input = true;
        while (input){
            System.out.print("请输入用户名：");
            username = scan.next();
            System.out.print("请输入密码：");
            password = scan.next();
            if (map.containsKey(username)){
                if (map.get(username).equals(password)){
                    input = false;
                    System.out.println(username+"用户，登录成功！");
                }else {
                    System.out.println("密码错误！");
                }
            }else {
                System.out.println("密码或用户名错误，请重新输入！");
            }
        }
    }
    public void reg(){

        while(true){
            System.out.println("请输入用户名:");
            username = scan.next();
            if(map.get(username)!=null){
                //如果存在
                System.out.println("该账号已经存在，请重新输入账号");
            }else{
                //不存在
                break;
            }
        }

        System.out.println("请输入密码：");
        password = scan.next();
        //添加用户到map集合
        map.put(username,password);
        System.out.println("注册成功!");
        System.out.println("当前注册的人员："+username);
    }
    //上班签到
    public void check_in(){
        if (Integer.valueOf(time)>9){
            System.out.println(username+"用户迟到，已经记录！");
            //写入到attendance+username.txt文件
            String saveFile = "attendance"+username+".txt";
            String fileContent = format+" "+username+"迟到";
            File file = new File(saveFile);
            FileOutputStream fos = null;
            OutputStreamWriter osw = null;
            try {
                if (!file.exists()){
                    fos = new FileOutputStream(file);
                }else {
                    fos = new FileOutputStream(file,true);
                }
                osw = new OutputStreamWriter(fos,"utf-8");
                osw.write(fileContent);
                osw.write("\r\n");
            } catch (IOException e) {
                e.printStackTrace();
            }finally {
                try {
                    if (osw != null) {
                        osw.close();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
                try {
                    if (fos != null) {
                        fos.close();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }else {
            System.out.println("签到成功！");

        }
        System.out.println(format);

    }
    //下班签出
    public void check_out(){
        if (Integer.valueOf(time)<18){
            System.out.println(username+"用户早退，已经记录!");
            //写入到attendance+username.txt文件
            String saveFile = "attendance"+username+".txt";
            String fileContent = format+" "+username+"早退";
            File file = new File(saveFile);
            FileOutputStream fos = null;
            OutputStreamWriter osw = null;
            try {
                if (!file.exists()){
                    fos = new FileOutputStream(file);
                }else {
                    fos = new FileOutputStream(file,true);
                }
                osw = new OutputStreamWriter(fos,"utf-8");
                osw.write(fileContent);
                osw.write("\r\n");
            } catch (IOException e) {
                e.printStackTrace();
            }finally {
                try {
                    if (osw != null) {
                        osw.close();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
                try {
                    if (fos != null) {
                        fos.close();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }else {
            System.out.println("签出成功！");

        }
        System.out.println(format);
    }
    //查询考勤信息
    public void display_record(){

        String filePath = "attendance"+username+".txt";
        InputStreamReader read = null;
        try {
            String encoding="utf-8";
            File file=new File(filePath);
            if(file.isFile() && file.exists()){ //判断文件是否存在
                read = new InputStreamReader(
                        new FileInputStream(file),encoding);//考虑到编码格式
                BufferedReader bufferedReader = new BufferedReader(read);
                String lineTxt = null;
                while((lineTxt = bufferedReader.readLine()) != null){
                    System.out.println(lineTxt);
                }
            }else{
                System.out.println("找不到指定的文件");
            }
        } catch (Exception e) {
            System.out.println("读取文件内容出错");
            e.printStackTrace();
        }finally {
            try {
                if (read != null) {
                    read.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}