import java.awt.*;
import javax.swing.*;
class Queen8{
	static final int QueenMax = 8;
	static int oktimes = 0;
	static int temp0[] = new int[QueenMax];
	static int temp1[] = new int[QueenMax];
	static int temp2[] = new int[QueenMax];
	static int temp3[] = new int[QueenMax];
	static int temp4[] = new int[QueenMax];
	static int temp5[] = new int[QueenMax];
	static int temp6[] = new int[QueenMax];
	static int temp7[] = new int[QueenMax];
	static int chess[] = new int[QueenMax];
	static int array[][]=new int[12][QueenMax];
	public static boolean Isequal(int a[],int b[]){
		boolean e=true;
		for(int j=0;j<a.length;j++){
			if(a[j]!=b[j]){
				e=false;
				continue;
			}
		}
		return e;
	}
	public static void placequeen(int num){  
		int i=0;
		boolean qsave[] = new boolean[QueenMax];
		for(;i<QueenMax;i++) qsave[i]=true;
		i=0;  
		while (i<num){
			qsave[chess[i]]=false;
			int k=num-i;
			if ( (chess[i]+k >= 0) && (chess[i]+k < QueenMax) ) qsave[chess[i]+k]=false;
			if ( (chess[i]-k >= 0) && (chess[i]-k < QueenMax) ) qsave[chess[i]-k]=false;
			i++;
		}
		for(i=0;i<QueenMax;i++){
			if (qsave[i]==false)continue;
			if (num<QueenMax-1){
				chess[num]=i;
				if(chess[0]<3) placequeen(num+1);
			}
			else{
				chess[num]=i;
				for(int n=0;n<QueenMax;n++){
					temp0[n]=chess[7-n];
					temp1[n]=7-chess[7-n];
					temp2[chess[n]] = n;
					temp3[chess[n]] = 7-n;
					temp4[7-chess[n]] = n;
					temp5[7-chess[n]] = 7-n;
				}
				boolean Addable=true;
				for(int n=0;n<oktimes;n++){
					if( (Isequal(array[n],temp0)) || (Isequal(array[n],temp1))
					 || (Isequal(array[n],temp2)) || (Isequal(array[n],temp3))
					 || (Isequal(array[n],temp4)) || (Isequal(array[n],temp5))
					  ){
						Addable=false;
						continue;
					}
				}
				if(Addable){
						for(int p=0;p<QueenMax;p++){
							array[oktimes][p]=chess[p];
						}
						oktimes++;	
					}
				}
			} 	
		}
	}
class MainFrame extends JFrame{
	JButton[][] Bloks;
	JPanel[] SuPanel;
	public MainFrame(String title){
		super(title);
		Bloks=new JButton[8][8];
		SuPanel=new JPanel[12];
		this.setLayout(new GridLayout(3,4,10,10));
		for(int i=0;i<12;i++){
			SuPanel[i]=new JPanel();
			SuPanel[i].setLayout(new GridLayout(8,8,0,0));
			for(int m=0;m<8;m++){
				for(int n=0;n<8;n++){
					Bloks[m][n]=new JButton();
					if(Queen8.array[i][m]==n){
						Bloks[m][n].setBackground(Color.BLACK);
						SuPanel[i].add(Bloks[m][n]);
						Bloks[m][n].setVisible(true);
					}
					else{
						Bloks[m][n].setBackground(Color.WHITE);
						SuPanel[i].add(Bloks[m][n]);
						Bloks[m][n].setVisible(true);
					}
				}
			}
			this.add(SuPanel[i]);
		}
		setVisible(true);
		setSize(400,350);
		setResizable(false);
	}	
}
public class Etqueen {
	public static void main(String[] args) {		
		for (int i=0;i<Queen8.QueenMax;i++)Queen8.chess[i]=-1;
		Queen8.placequeen(0);
		System.out.println("\n八皇后共有"+Queen8.oktimes+"个解法(除过镜像等转换等情况)");
		MainFrame me=new MainFrame("八皇后(除过镜像等转换等情况)");
		}
}
