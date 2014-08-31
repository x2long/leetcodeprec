import java.awt.*;
import javax.swing.*;
class Queen8{
	static final int QueenMax = 8;
	static int oktimes = 0;
	static int chess[] = new int[QueenMax];
	static int array[][]=new int[12][QueenMax];
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
				if(chess[0]<4) placequeen(num+1);
			}
			else{
				chess[num]=i;
				oktimes++;
				System.out.println("这是第"+oktimes+"个解法 如下:");
				System.out.println("第n行: 1 2 3 4 5 6 7 8");
				for (i=0;i<QueenMax;i++){
					String row="第"+(i+1)+"行: ";
					if (chess[i]==0);
					else
						for(int j=0;j<chess[i];j++) row+="--";
					row+="++";
					int j = chess[i];
					while(j<QueenMax-1){row+="--";j++;}
					System.out.println(row);
					}
				}
			} 	
		}
	}
public class Etqueen {
	public static void main(String[] args) {		
		for (int i=0;i<Queen8.QueenMax;i++)Queen8.chess[i]=-1;
		Queen8.placequeen(0);
		System.out.println("\n\n\n八皇后共有"+Queen8.oktimes+"个解法 made by x2long 2014");
		}
}

