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

	public class PurchaseDataArray
	{

		[XmlArray("purchases")]
		[XmlArrayItem("purchase")]
		public List<PurchaseData> data = new List<PurchaseData>();
	}
	[Serializable]
	[XmlRoot("dataPurchase")]
	public class PurchaseData
	{
		[XmlAttribute("client")]
		public ClientData client = new ClientData();
		[XmlAttribute("date")]
		public DateTime date;

		[XmlArray("tovars")]
		[XmlArrayItem("tovar")]
		public List<TovarData> data = new List<TovarData>();

	}

	class Purchase
	{
		string nameFile = "purchase.txt";
		XmlSerializer serializer = new XmlSerializer(typeof(PurchaseDataArray));
		public void setTovar(PurchaseData dataArray)
		{
			PurchaseDataArray allData = getPurchase();
			allData.data.Add(dataArray);
			using (var fs = new FileStream(nameFile, FileMode.Create))
			{
				serializer.Serialize(fs, allData);
			}
		}
		public PurchaseDataArray getPurchase()
		{
			PurchaseDataArray PurchaseData = new PurchaseDataArray();
			Stream streamout = new FileStream(nameFile, FileMode.Open, FileAccess.Read);
			if (streamout.Length == 0)
			{
				streamout.Close();
				return PurchaseData;
			}
			PurchaseData = (PurchaseDataArray)serializer.Deserialize(streamout);
			streamout.Close();
			return PurchaseData;
		}
		public PurchaseDataArray getTovarConsole()
		{
			int index = 0;
			PurchaseDataArray purchaseData = getPurchase();
			Console.WriteLine("Номер " + "ФИО  " + "Возраст  " + "Номер телефона  " + "Дата заказа  ");
			foreach (PurchaseData data in purchaseData.data)
			{
				index++;
				Console.WriteLine(data.client.FIO + " " + data.client.age + " " + data.client.tlf + " " + data.date);
				 
			}
			return purchaseData;
		}

		public void deleteTovar(int indexDelete)
		{
			int index = 0;
			PurchaseDataArray data = getPurchase();
			PurchaseDataArray dataSetArray = new PurchaseDataArray();

			foreach (PurchaseData dataIndex in data.data)
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
	}
}
