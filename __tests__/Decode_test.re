open Jest;
open Decode;
open Expect;

describe("#currentPlayingState", () => {
  test("stopped", () =>
    expect(currentPlayingState("stopped")) |> toEqual(Stopped)
  );

  test("playing", () =>
    expect(currentPlayingState("playing")) |> toEqual(Playing)
  );

  test("undefined", () =>
    expect(currentPlayingState("undefined")) |> toEqual(UnknownState)
  );
});

describe("currentTrackResponse", () => {
  test("parse current queue without track data", () => {
    let mockPayload =
      {|{
              "position": 0,
              "duration": 0,
              "queuePosition": 0,
              "uri": null
            }|}
      |> Json.parseOrRaise;

    let expected: currentTrackResponse = {
      album: None,
      albumArtURI: "",
      albumArtURL: "",
      artist: "",
      duration: 0.,
      position: 0.,
      queuePosition: 0.,
      title: "",
      uri: "",
    };

    expect(currentTrackResponse(mockPayload)) |> toEqual(expected);
  });

  test("parse current queue with track data", () => {
    let mockPayload =
      {|{
              "album": "Sempiternal",
              "albumArtURI": "some-art-uri",
              "albumArtURL": "some-art-url",
              "artist": "Bring Me The Horizon",
              "duration": 320,
              "position": 1,
              "queuePosition": 3,
              "title": "Hospital for Souls",
              "uri": "some-uri"
            }|}
      |> Json.parseOrRaise;

    let expected: currentTrackResponse = {
      album: Some("Sempiternal"),
      albumArtURI: "some-art-uri",
      albumArtURL: "some-art-url",
      artist: "Bring Me The Horizon",
      duration: 320.,
      position: 1.,
      queuePosition: 3.,
      title: "Hospital for Souls",
      uri: "some-uri",
    };

    expect(currentTrackResponse(mockPayload)) |> toEqual(expected);
  });
});
