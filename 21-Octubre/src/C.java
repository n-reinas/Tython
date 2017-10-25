import java.math.BigInteger;
import java.util.Scanner;

public class C {

	public static void inic(BigInteger mat[][],int n){
		mat[0][0]=new BigInteger("1");
		for(int i=1;i<n;i++){
			mat[0][i]=new BigInteger("0");
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<n;j++){
				mat[i][j]=new BigInteger("0");
				mat[i][j]=mat[i][j].add(mat[i-1][j]);
				if(j!=0){
					mat[i][j]=mat[i][j].add(mat[i-1][j-1]);
				}
			}
		}
		
		
		
		
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger mat[][]=new BigInteger[101][101];
		inic(mat,101);
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		for(int i=0;i<t;i++){
			int n=in.nextInt();
			if(n==0){
				System.out.println(1);
			}else if(n==1){
				System.out.println("x+y");
				
			}else if(n==2){
				System.out.println("x^2+2xy+y^2");
			}else{
			
				for(int j=0;j<=n;j++){
					if(j!=0&&j!=n){
						System.out.print(mat[n][j]);
					}
						
					if(j!=n&&j!=0&&j!=1&&j!=n-1){
						System.out.print("x^"+(n-j)+"y^"+j);
						System.out.print("+");
					}
					if(j==1){
						System.out.print("x^"+(n-j)+"y+");
					}
					if(j==n-1){
						System.out.print("x"+"y^"+j+"+");
					}
					if(j==0){
						System.out.print("x^"+(n-j)+"+");
					}
					if(j==n){
						System.out.print("y^"+j);
					}
				}
				System.out.println();
			}
			
		}
	}

}
