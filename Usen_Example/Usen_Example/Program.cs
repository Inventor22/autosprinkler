using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Usen_Example
{
    class Program
    {
        //SerialPort robot = new SerialPort("COM8", 9600);
        public static SerialPort moistureSensor = new SerialPort("COM4", 1200);

        static void Main(string[] args)
        {
            moistureSensor.Open();

            if (moistureSensor.IsOpen)
            {
                Console.WriteLine("sensor paired!");
            } else
            {
                Console.WriteLine("sensor not paired!");
                return;
            }

            test2();
        }

        static void test0()
        {
            int i = 0;
            while (true)
            {
                Thread.Sleep(2000);
                string s = "ABC";
                moistureSensor.Write(s);
                Console.WriteLine("Sent: {0}", s);

                while (moistureSensor.BytesToRead >= 1)
                {
                    char c = (char)moistureSensor.ReadByte();
                    Console.WriteLine(c);
                }
            }
        }

        static void test1()
        {
            int i = 0;
            while (true)
            {
                Thread.Sleep(2000);
                char[] buf = { 'A', 'B', 'C', 'D' };
                moistureSensor.Write(buf, i % 4, 1);
                Thread.Sleep(10);
                moistureSensor.Write(buf, i % 4, 1);
                Console.WriteLine("Sent: {0}", buf[i++ % 4]);
                Thread.Sleep(100);

                while (moistureSensor.BytesToRead >= 1)
                {
                    char c = (char)moistureSensor.ReadByte();
                    Console.WriteLine(c);
                }
                Console.WriteLine();
            }
        }

        static void test2()
        {
            while (true)
            {
                Thread.Sleep(2000);
                char[] buf = { 'A', 'B', 'C', 'D' };
                Console.WriteLine("Sending: {0}", new string(buf));
                moistureSensor.Write(buf, 0, 4);
                Thread.Sleep(100);

                string s = "";
                while (moistureSensor.BytesToRead >= 1)
                {
                    s += (char)moistureSensor.ReadByte();
                }
                Console.WriteLine(s);
            }
        }
    }
}
