import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main 
{
    public static void main(String args[])
    {
        File in = new File("input.txt");
        Scanner read = new Scanner(in);
        buff = args.length == 1 ? args[0] : "";
        
        try
        {
            while(read.hasNextLine())
            {
                buff = read.nextLine();
                String t = buff;
            
                if(A() && i = t.length)
                {
                    System.out.println("The string \"" + t + "\" is in the language.\n");
                }
                else
                {
                    System.out.println(("The string \"" + t + "\" is not in the language.\n"));
                }
            }
            read.close();
        }
        catch (FileNotFoundException e) 
        {
        System.out.println("File not Found.");
        e.printStackTrace();
        }
        
    }
    private static boolean A()
    {
        if(I())
        {
            if(i < buff.length() && buff.charAt(i) == '=')
            {
                ++i;
                if(E())
                {
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    private static boolean I()
    {
        if(C())
        {
            if(buff.charAt(i) != '=')
            {
                if(I())
                {
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }

    private static boolean C()
    {
        if(i < buff.length() && 'a' <= buff.charAt(i) && buff.charAt(i) <= 'z')
        {
            ++i;
            return true;
        }
        return false;
    }

    private static boolean E()
    {
        if(P())
        {
            if(O())
            {
                if(P())
                {
                    return true;
                }
            }
            return true;
        }
        return false;
    }

    private static boolean P()
    {
        if(I())
        {
            return true;
        }
        else if(L())
        {
            return true;
        }
        else if(U())
        {
            if(L())
            {
                return true;
            }
            return false;
        }
        else if(U())
        {
            if(I())
            {
                return true;
            }
            return false;
        }
        else if(i < buff.length() && buff.charAt(i) == '(')
        {
            ++i;
            if(E())
            {
                if(i < buff.length() && buff.charAt(i) == ')')
                {
                    ++i;
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean O()
    {
        if(i<buff.length && (buff.charAt(i) == '+' || buff.charAt(i) == '-' || buff.charAt(i) == '*' || buff.charAt(i) == '/' || buff.charAt(i) == "**"))
        {
            ++i;
            return true;
        }
        return false;
    }

    private static boolean L()
    {
        if(D())
        {
            if(L())
            {
                return true;
            }
            return false;
        }
        return false;
    }

    private static boolean U()
    {
        if(i < buff.length && (buff.charAt(i) == '+' || buff.charAt(i) == '-' || buff.charAt(i) == '!'))
        {
            ++i;
            return true;
        }
        return false;
    }

    private static boolean D()
    {
        if(i < buff.length() && '0' <= buff.charAt(i) && buff.charAt(i) <= '9')
        {
            ++i;
            return true;
        }
        return false;
    }

        
}
