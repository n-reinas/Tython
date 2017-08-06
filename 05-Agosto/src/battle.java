import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class battle {
	
	public static Queue defence(String S){
		int i=0;
		
		Queue<Character> ans=new LinkedList<Character>();
		int asci='R'+'L'+'B';
		while(i<S.length()){
			if(i<=S.length()-3){
			if(S.charAt(i)+S.charAt(i+1)+S.charAt(i+2)==asci){
				ans.add('C');
				i+=3;
			}else{
				if(S.charAt(i)=='R'){
					ans.add('S');
				}
				if(S.charAt(i)=='B'){
					ans.add('K');
				}
				if(S.charAt(i)=='L'){
					ans.add('H');
				}
				i+=1;
				
			}
			}else{
				if(S.charAt(i)=='R'){
					ans.add('S');
				}
				if(S.charAt(i)=='B'){
					ans.add('K');
				}
				if(S.charAt(i)=='L'){
					ans.add('H');
				}
				i+=1;
			}	
		}
		return ans;
	}
	
	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in=new Scanner(System.in);
		String S=in.next();
		Queue ans=defence(S);
		while(!ans.isEmpty()){
			System.out.print(ans.poll());
		}
		

	}
	
}
