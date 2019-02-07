import java.util.Scanner;

public class BFI{

	private static byte array[];
	private static int ptr;
	private static Scanner sc;

	public static void main(String[] args){
		sc = new Scanner(System.in);
		array = new byte[30_000];
		ptr = 0;
		String inp = sc.nextLine().trim().replace("\\s+", "");
		process(inp);
	}

	static void process(String inp){
		for(int i=0; i<inp.length(); i++){
			switch(inp.charAt(i)){
				case '[':
					int e = i+1, c=0;
					while(inp.charAt(e) != ']' || c!=0){
						if(inp.charAt(e) == '[')
							c++;
						else if(inp.charAt(e) == ']')
							c--;
						e++;
					}
					while(array[ptr] != 0){
						process(inp.substring(i+1, e));
					}
					i=e;
				break;
				case '+':
					array[ptr]++;
				break;
				case '-':
					array[ptr]--;
				break;
				case '>':
					ptr++;
				break;
				case '<':
					ptr--;
				break;
				case '.':
					System.out.print((char)array[ptr]);
				break;
				case ',':
					array[ptr] = (byte)(sc.nextLine().trim().charAt(0));
				break;
				default:
					System.out.println("Invalid token!");
					System.exit(0);
			}
		}
	}
}
