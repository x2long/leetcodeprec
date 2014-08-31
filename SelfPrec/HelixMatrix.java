/*
  螺旋矩阵的构造，需要考虑维度的奇偶性、方向、发散或者收敛、开始位置
  方向和发散性在某种角度看是对称的
  http://www.cnblogs.com/eshizhan/archive/2010/06/01/1749013.html
*/
import java.util.Scanner;
class Arrays{
    int size;
    int array[][];
    public Arrays(int n){
        size = n;
        array = new int[size][size];
        for(int i =0;i<size;i++)
            for(int j=0;j<size;j++)
                 array[i][j] = 0;
    }
    public void Generate(){
        int nr=0,nd=0,nl=0,nu=0,i=1,j=0;
        while(i<size*size){
            for(j=0;j<(size-2*nr);j++){
                array[nr][j+nu]=i++;
            }
	    nr++;
            for(j=0;j<(size-2*nd-1);j++){
                array[j+nr][size-nd-1]=i++;
            }
            nd++;
            for(j=0;j<(size-2*nl-1);j++){
                array[size-1-nl][size-1-nd-j]=i++;
            }
            nl++;
            for(j=0;j<(size-2*(nu+1));j++){
                array[size-1-nl-j][nu]=i++;
            }
            nu++;
        }
    }
}
