using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;

namespace mysor
{


	public class ClientDataArray
    {

		[XmlArray("clients")]
		[XmlArrayItem("client")]
		public List<ClientData> data = new List<ClientData>();
	}
	[Serializable]
	[XmlRoot("dataClient")]
	public class ClientData
	{
		[XmlAttribute("FIO")]
		public string FIO;
		[XmlAttribute("age")]
		public string age;
		[XmlAttribute("tlf")]
		public string tlf;
    }

	class Client
	{
		string nameFile = "students.txt";
		XmlSerializer serializer = new XmlSerializer(typeof(ClientDataArray));

		public void setClient(ClientData dataArray) {
			ClientDataArray allData = getClient();
			allData.data.Add(dataArray);
			using (var fs = new FileStream(nameFile, FileMode.Create))
			{
				serializer.Serialize(fs, allData);
			}

		}
		public void deleteClient(int indexDelete)
        {
			int index = 0;
			ClientDataArray data = getClient();
			ClientDataArray dataSetArray = new ClientDataArray();
 
			foreach (ClientData dataIndex  in data.data)
            {
				if (index != indexDelete)
                {
 					dataSetArray.data.Add(dataIndex);
				}
				index++;
			}
			using (var fs = new FileStream(nameFile, FileMode.Create))
			{

				serializer.Serialize(fs, dataSetArray);
			}
		}
		public ClientDataArray getConsole()
        {
			int index = 0;
			ClientDataArray clientData = getClient();
			Console.WriteLine("Номер " + "ФИО  " + "Возраст  " + "Номер телефона  ");
			foreach (ClientData data in clientData.data)
			{
				index++;
				Console.WriteLine(index + "    " + data.FIO + "    " + data.age + "    " + data.tlf);
			}
			return clientData;
		}
		public ClientDataArray getClient() {
			ClientDataArray clientData = new ClientDataArray();
			Stream streamout = new FileStream("students.txt", FileMode.Open, FileAccess.Read);
			if(streamout.Length == 0) {
				streamout.Close();
				return clientData;
			}
			clientData = (ClientDataArray)serializer.Deserialize(streamout);
			streamout.Close();
			return clientData;	 
		}
	}
}

 
 