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
            System.out.println("��ѡ����      1.(ע��)    2.(��½)");
            System.out.println("-------------------------------------------------------");

            int option = 0;
            boolean b = true;
            while (b){
                try {
                    option = scan.nextInt();
                    b = false;
                } catch (Exception e) {
                    System.out.println("�����������������!");
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
                    System.out.println("���ѡ������,����������");
            }
        }

    }
    public void menu(){

        System.out.println("-------------------------------------------------------");
        System.out.println("                 1�����ϰ�ǩ��");
        System.out.println("                 2�����°�ǩ��");
        System.out.println("                 3����������Ϣ����");
        System.out.println("                 4�����˳�");
        System.out.println("-------------------------------------------------------");
        int choice = 0;
        boolean b = true;
        while (b){
            try {
                choice = scan.nextInt();
                b = false;
            } catch (Exception e) {
                System.out.println("�����������������!");
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
                System.out.println(username+"�û����˳���");
                circulation = false;
                break;
            default:
                System.out.println("�������");
        }
    }
    public void login(){
        boolean input = true;
        while (input){
            System.out.print("�������û�����");
            username = scan.next();
            System.out.print("���������룺");
            password = scan.next();
            if (map.containsKey(username)){
                if (map.get(username).equals(password)){
                    input = false;
                    System.out.println(username+"�û�����¼�ɹ���");
                }else {
                    System.out.println("�������");
                }
            }else {
                System.out.println("������û����������������룡");
            }
        }
    }
    public void reg(){

        while(true){
            System.out.println("�������û���:");
            username = scan.next();
            if(map.get(username)!=null){
                //�������
                System.out.println("���˺��Ѿ����ڣ������������˺�");
            }else{
                //������
                break;
            }
        }

        System.out.println("���������룺");
        password = scan.next();
        //����û���map����
        map.put(username,password);
        System.out.println("ע��ɹ�!");
        System.out.println("��ǰע�����Ա��"+username);
    }
    //�ϰ�ǩ��
    public void check_in(){
        if (Integer.valueOf(time)>9){
            System.out.println(username+"�û��ٵ����Ѿ���¼��");
            //д�뵽attendance+username.txt�ļ�
            String saveFile = "attendance"+username+".txt";
            String fileContent = format+" "+username+"�ٵ�";
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
            System.out.println("ǩ���ɹ���");

        }
        System.out.println(format);

    }
    //�°�ǩ��
    public void check_out(){
        if (Integer.valueOf(time)<18){
            System.out.println(username+"�û����ˣ��Ѿ���¼!");
            //д�뵽attendance+username.txt�ļ�
            String saveFile = "attendance"+username+".txt";
            String fileContent = format+" "+username+"����";
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
            System.out.println("ǩ���ɹ���");

        }
        System.out.println(format);
    }
    //��ѯ������Ϣ
    public void display_record(){

        String filePath = "attendance"+username+".txt";
        InputStreamReader read = null;
        try {
            String encoding="utf-8";
            File file=new File(filePath);
            if(file.isFile() && file.exists()){ //�ж��ļ��Ƿ����
                read = new InputStreamReader(
                        new FileInputStream(file),encoding);//���ǵ������ʽ
                BufferedReader bufferedReader = new BufferedReader(read);
                String lineTxt = null;
                while((lineTxt = bufferedReader.readLine()) != null){
                    System.out.println(lineTxt);
                }
            }else{
                System.out.println("�Ҳ���ָ�����ļ�");
            }
        } catch (Exception e) {
            System.out.println("��ȡ�ļ����ݳ���");
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